#!/bin/bash

set -o nounset
set -o errexit
set -o pipefail
set -o noclobber
set -o noglob

# Usage:
# tag-docker-image-no-pull.sh repo image from-tag to-tag /path/to/.docker/config.json

REPOSITORY="$1"
IMAGE_NAME="$2"
FROM_TAG="$3"
TO_TAG="$4"
CONFIG_PATH=${5-"/.docker/config.json"}

USAGE="Usage: ./tag-docker-image-no-pull.sh repo image from-tag to-tag /path/to/.docker/config.json"

if [[ -z "${REPOSITORY}" || -z "${IMAGE_NAME}" || -z "${FROM_TAG}" || -z "${TO_TAG}" || -z "${CONFIG_PATH}" ]]; then
  echo "ERROR"
  echo "$USAGE"
  exit
fi

CONTENT_TYPE="application/vnd.docker.distribution.manifest.v2+json"
DOCKER_URL="https://registry-1.docker.io"

# Get Username and password from docker config file
DOCKER_AUTH=$(cat $CONFIG_PATH | jq -r '.auths | .["https://index.docker.io/v1/"] | .auth')
DOCKER_CREDS=$(echo -n "$DOCKER_AUTH" | base64 -d)
DOCKER_USERNAME=$(echo -n "$DOCKER_CREDS" | awk -F':' '{print $1}')
DOCKER_PASSWORD=$(echo -n "$DOCKER_CREDS" | awk -F':' '{print $2}')

# Get authentication token
DOCKER_TOKEN=$(curl -s -u $DOCKER_CREDS "https://auth.docker.io/token?service=registry.docker.io&scope=repository:$REPOSITORY/$IMAGE_NAME:pull,push" | jq -r '.token')

# Get the current docker manifest of the current tag
MANIFEST=$(curl -H "Accept: ${CONTENT_TYPE}" -H "Authorization: Bearer ${DOCKER_TOKEN}" "${DOCKER_URL}/v2/${REPOSITORY}/${IMAGE_NAME}/manifests/${FROM_TAG}")
echo "$MANIFEST"

# Adding new tag based on manifest of previous tag
curl -v -X PUT -H "Content-Type: ${CONTENT_TYPE}" -H "Authorization: Bearer ${DOCKER_TOKEN}" -d "${MANIFEST}" "${DOCKER_URL}/v2/${REPOSITORY}/{$IMAGE_NAME}/manifests/${TO_TAG}"


