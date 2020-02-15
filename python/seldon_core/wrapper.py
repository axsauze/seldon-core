import grpc
from concurrent import futures
from flask import jsonify, Flask, send_from_directory, request
from flask_cors import CORS
import logging
from seldon_core.utils import seldon_message_to_json, json_to_feedback
from seldon_core.flask_utils import get_request
import seldon_core.seldon_methods
from seldon_core.flask_utils import (
    SeldonMicroserviceException,
    ANNOTATION_GRPC_MAX_MSG_SIZE,
)
from seldon_core.proto import prediction_pb2_grpc
import os

logger = logging.getLogger(__name__)

PRED_UNIT_ID = os.environ.get("PREDICTIVE_UNIT_ID")  # Container name
PREDICTOR_ID = os.environ.get("PREDICTOR_ID")  # Predictor spec name
DEPLOYMENT_ID = os.environ.get("SELDON_DEPLOYMENT_ID")  # Deployment name


def get_kafka_worker(
    user_model,
    log_level="INFO",
    tracing=None,
    host="0.0.0.0",
    topic_partitions=1,
    port=9092,
):
    if not all([bool(PRED_UNIT_ID), bool(PREDICTOR_ID), bool(DEPLOYMENT_ID)]):
        # TODO: update for correct prediction
        raise Exception("Predictie unit, predictor id or deployment id not set")
    import faust

    TOPIC_PREFIX = f"{DEPLOYMENT_ID}-{PRED_UNIT_ID}"
    KAFKA_BROKERS = f"kafka://{host}:{port}"
    # TODO: Add more customizable parameters from env
    # TODO: Add and test tracing
    app = faust.App(
        __name__,
        broker=KAFKA_BROKERS,
        key_serializer="json",
        value_serializer="json",
        topic_partitions=topic_partitions,
        tracing=tracing,
    )

    # At this point only the predict function is available for streaming
    # TODO: Explore adding functionality for more than just the predict function
    # if any(hasattr(user_model, attr) for attr in
    #        ["predict", "predict_raw", "predict_grpc", "predict_rest"]):

    predict_topic_input = app.topic(f"{TOPIC_PREFIX}-predict-input")
    predict_topic_output = app.topic(f"{TOPIC_PREFIX}-predict-output")

    @app.agent(predict_topic_input)
    async def predict(predict_stream):
        async for key, value in predict_stream.items():
            logger.debug(f"KAFKA data content ID [{key}]. CONTENT: [{value}].")
            response = seldon_core.seldon_methods.predict(user_model, value)
            logger.debug(f"KAFKA Data response: {response}")
            await predict_topic_output.send(key=key, value=response)

    print(f"LOG LEVEL PROVIDED {log_level}")
    worker = faust.Worker(app, loglevel=log_level)
    return worker


def get_rest_microservice(user_model):
    app = Flask(__name__, static_url_path="")
    CORS(app)

    _set_flask_app_configs(app)

    if hasattr(user_model, "model_error_handler"):
        logger.info("Registering the custom error handler...")
        app.register_blueprint(user_model.model_error_handler)

    @app.errorhandler(SeldonMicroserviceException)
    def handle_invalid_usage(error):
        response = jsonify(error.to_dict())
        logger.error("%s", error.to_dict())
        response.status_code = error.status_code
        return response

    @app.route("/seldon.json", methods=["GET"])
    def openAPI():
        return send_from_directory("", "openapi/seldon.json")

    @app.route("/predict", methods=["GET", "POST"])
    @app.route("/api/v1.0/predictions", methods=["POST"])
    @app.route("/api/v0.1/predictions", methods=["POST"])
    def Predict():
        requestJson = get_request()
        logger.debug("REST Request: %s", request)
        response = seldon_core.seldon_methods.predict(user_model, requestJson)
        json_response = jsonify(response)
        if "status" in response and "code" in response["status"]:
            json_response.status_code = response["status"]["code"]

        logger.debug("REST Response: %s", response)
        return json_response

    @app.route("/send-feedback", methods=["GET", "POST"])
    @app.route("/api/v1.0/feedback", methods=["POST"])
    @app.route("/api/v0.1/feedback", methods=["POST"])
    def SendFeedback():
        requestJson = get_request()
        logger.debug("REST Request: %s", request)
        requestProto = json_to_feedback(requestJson)
        logger.debug("Proto Request: %s", requestProto)
        responseProto = seldon_core.seldon_methods.send_feedback(
            user_model, requestProto, PRED_UNIT_ID
        )
        jsonDict = seldon_message_to_json(responseProto)
        return jsonify(jsonDict)

    @app.route("/transform-input", methods=["GET", "POST"])
    def TransformInput():
        requestJson = get_request()
        logger.debug("REST Request: %s", request)
        response = seldon_core.seldon_methods.transform_input(user_model, requestJson)
        logger.debug("REST Response: %s", response)
        return jsonify(response)

    @app.route("/transform-output", methods=["GET", "POST"])
    def TransformOutput():
        requestJson = get_request()
        logger.debug("REST Request: %s", request)
        response = seldon_core.seldon_methods.transform_output(user_model, requestJson)
        logger.debug("REST Response: %s", response)
        return jsonify(response)

    @app.route("/route", methods=["GET", "POST"])
    def Route():
        requestJson = get_request()
        logger.debug("REST Request: %s", request)
        response = seldon_core.seldon_methods.route(user_model, requestJson)
        logger.debug("REST Response: %s", response)
        return jsonify(response)

    @app.route("/aggregate", methods=["GET", "POST"])
    def Aggregate():
        requestJson = get_request()
        logger.debug("REST Request: %s", request)
        response = seldon_core.seldon_methods.aggregate(user_model, requestJson)
        logger.debug("REST Response: %s", response)
        return jsonify(response)

    @app.route("/health/ping", methods=["GET"])
    def HealthPing():
        """
        Lightweight endpoint to check the liveness of the REST endpoint
        """
        return "pong"

    @app.route("/health/status", methods=["GET"])
    def HealthStatus():
        logger.debug("REST Health Status Request")
        response = seldon_core.seldon_methods.health_status(user_model)
        logger.debug("REST Health Status Response: %s", response)
        return jsonify(response)

    @app.route("/metadata", methods=["GET"])
    def Metadata():
        logger.debug("REST Metadata Request")
        response = seldon_core.seldon_methods.metadata(user_model)
        logger.debug("REST Metadata Response: %s", response)
        return jsonify(response)

    return app


def _set_flask_app_configs(app):
    """
    Set the configs for the flask app based on environment variables
    :param app:
    :return:
    """
    env_to_config_map = {
        "FLASK_JSONIFY_PRETTYPRINT_REGULAR": "JSONIFY_PRETTYPRINT_REGULAR",
        "FLASK_JSON_SORT_KEYS": "JSON_SORT_KEYS",
    }

    for env_var, config_name in env_to_config_map.items():
        if os.environ.get(env_var):
            # Environment variables come as strings, convert them to boolean
            bool_env_value = os.environ.get(env_var).lower() == "true"
            app.config[config_name] = bool_env_value


# ----------------------------
# GRPC
# ----------------------------


class SeldonModelGRPC(object):
    def __init__(self, user_model):
        self.user_model = user_model

    def Predict(self, request_grpc, context):
        return seldon_core.seldon_methods.predict(self.user_model, request_grpc)

    def SendFeedback(self, feedback_grpc, context):
        return seldon_core.seldon_methods.send_feedback(
            self.user_model, feedback_grpc, PRED_UNIT_ID
        )

    def TransformInput(self, request_grpc, context):
        return seldon_core.seldon_methods.transform_input(self.user_model, request_grpc)

    def TransformOutput(self, request_grpc, context):
        return seldon_core.seldon_methods.transform_output(
            self.user_model, request_grpc
        )

    def Route(self, request_grpc, context):
        return seldon_core.seldon_methods.route(self.user_model, request_grpc)

    def Aggregate(self, request_grpc, context):
        return seldon_core.seldon_methods.aggregate(self.user_model, request_grpc)


def get_grpc_server(user_model, annotations={}, trace_interceptor=None):
    seldon_model = SeldonModelGRPC(user_model)
    options = []
    if ANNOTATION_GRPC_MAX_MSG_SIZE in annotations:
        max_msg = int(annotations[ANNOTATION_GRPC_MAX_MSG_SIZE])
        logger.info("Setting grpc max message and receive length to %d", max_msg)
        options.append(("grpc.max_message_length", max_msg))
        options.append(("grpc.max_send_message_length", max_msg))
        options.append(("grpc.max_receive_message_length", max_msg))

    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10), options=options)

    if trace_interceptor:
        from grpc_opentracing.grpcext import intercept_server

        server = intercept_server(server, trace_interceptor)

    prediction_pb2_grpc.add_GenericServicer_to_server(seldon_model, server)
    prediction_pb2_grpc.add_ModelServicer_to_server(seldon_model, server)
    prediction_pb2_grpc.add_TransformerServicer_to_server(seldon_model, server)
    prediction_pb2_grpc.add_OutputTransformerServicer_to_server(seldon_model, server)
    prediction_pb2_grpc.add_CombinerServicer_to_server(seldon_model, server)
    prediction_pb2_grpc.add_RouterServicer_to_server(seldon_model, server)
    prediction_pb2_grpc.add_SeldonServicer_to_server(seldon_model, server)

    return server
