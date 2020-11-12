// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow/tensorflow/core/framework/resource_handle.proto

#ifndef PROTOBUF_tensorflow_2ftensorflow_2fcore_2fframework_2fresource_5fhandle_2eproto__INCLUDED
#define PROTOBUF_tensorflow_2ftensorflow_2fcore_2fframework_2fresource_5fhandle_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "tensorflow/core/framework/tensor_shape.pb.h"
#include "tensorflow/core/framework/types.pb.h"
// @@protoc_insertion_point(includes)

namespace tensorflow {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_tensorflow_2ftensorflow_2fcore_2fframework_2fresource_5fhandle_2eproto();
void protobuf_AssignDesc_tensorflow_2ftensorflow_2fcore_2fframework_2fresource_5fhandle_2eproto();
void protobuf_ShutdownFile_tensorflow_2ftensorflow_2fcore_2fframework_2fresource_5fhandle_2eproto();

class ResourceHandleProto;
class ResourceHandleProto_DtypeAndShape;

// ===================================================================

class ResourceHandleProto_DtypeAndShape : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:tensorflow.ResourceHandleProto.DtypeAndShape) */ {
 public:
  ResourceHandleProto_DtypeAndShape();
  virtual ~ResourceHandleProto_DtypeAndShape();

  ResourceHandleProto_DtypeAndShape(const ResourceHandleProto_DtypeAndShape& from);

  inline ResourceHandleProto_DtypeAndShape& operator=(const ResourceHandleProto_DtypeAndShape& from) {
    CopyFrom(from);
    return *this;
  }

  inline ::google::protobuf::Arena* GetArena() const { return GetArenaNoVirtual(); }
  inline void* GetMaybeArenaPointer() const {
    return MaybeArenaPtr();
  }
  static const ::google::protobuf::Descriptor* descriptor();
  static const ResourceHandleProto_DtypeAndShape& default_instance();

  void UnsafeArenaSwap(ResourceHandleProto_DtypeAndShape* other);
  void Swap(ResourceHandleProto_DtypeAndShape* other);

  // implements Message ----------------------------------------------

  inline ResourceHandleProto_DtypeAndShape* New() const { return New(NULL); }

  ResourceHandleProto_DtypeAndShape* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ResourceHandleProto_DtypeAndShape& from);
  void MergeFrom(const ResourceHandleProto_DtypeAndShape& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ResourceHandleProto_DtypeAndShape* other);
  protected:
  explicit ResourceHandleProto_DtypeAndShape(::google::protobuf::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::google::protobuf::Arena* arena);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .tensorflow.DataType dtype = 1;
  void clear_dtype();
  static const int kDtypeFieldNumber = 1;
  ::tensorflow::DataType dtype() const;
  void set_dtype(::tensorflow::DataType value);

  // optional .tensorflow.TensorShapeProto shape = 2;
  bool has_shape() const;
  void clear_shape();
  static const int kShapeFieldNumber = 2;
  private:
  void _slow_mutable_shape();
  void _slow_set_allocated_shape(
      ::google::protobuf::Arena* message_arena, ::tensorflow::TensorShapeProto** shape);
  ::tensorflow::TensorShapeProto* _slow_release_shape();
  public:
  const ::tensorflow::TensorShapeProto& shape() const;
  ::tensorflow::TensorShapeProto* mutable_shape();
  ::tensorflow::TensorShapeProto* release_shape();
  void set_allocated_shape(::tensorflow::TensorShapeProto* shape);
  ::tensorflow::TensorShapeProto* unsafe_arena_release_shape();
  void unsafe_arena_set_allocated_shape(
      ::tensorflow::TensorShapeProto* shape);

  // @@protoc_insertion_point(class_scope:tensorflow.ResourceHandleProto.DtypeAndShape)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  friend class ::google::protobuf::Arena;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  bool _is_default_instance_;
  ::tensorflow::TensorShapeProto* shape_;
  int dtype_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_tensorflow_2ftensorflow_2fcore_2fframework_2fresource_5fhandle_2eproto();
  friend void protobuf_AssignDesc_tensorflow_2ftensorflow_2fcore_2fframework_2fresource_5fhandle_2eproto();
  friend void protobuf_ShutdownFile_tensorflow_2ftensorflow_2fcore_2fframework_2fresource_5fhandle_2eproto();

  void InitAsDefaultInstance();
  static ResourceHandleProto_DtypeAndShape* default_instance_;
};
// -------------------------------------------------------------------

class ResourceHandleProto : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:tensorflow.ResourceHandleProto) */ {
 public:
  ResourceHandleProto();
  virtual ~ResourceHandleProto();

  ResourceHandleProto(const ResourceHandleProto& from);

  inline ResourceHandleProto& operator=(const ResourceHandleProto& from) {
    CopyFrom(from);
    return *this;
  }

  inline ::google::protobuf::Arena* GetArena() const { return GetArenaNoVirtual(); }
  inline void* GetMaybeArenaPointer() const {
    return MaybeArenaPtr();
  }
  static const ::google::protobuf::Descriptor* descriptor();
  static const ResourceHandleProto& default_instance();

  void UnsafeArenaSwap(ResourceHandleProto* other);
  void Swap(ResourceHandleProto* other);

  // implements Message ----------------------------------------------

  inline ResourceHandleProto* New() const { return New(NULL); }

  ResourceHandleProto* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ResourceHandleProto& from);
  void MergeFrom(const ResourceHandleProto& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ResourceHandleProto* other);
  protected:
  explicit ResourceHandleProto(::google::protobuf::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::google::protobuf::Arena* arena);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef ResourceHandleProto_DtypeAndShape DtypeAndShape;

  // accessors -------------------------------------------------------

  // optional string device = 1;
  void clear_device();
  static const int kDeviceFieldNumber = 1;
  const ::std::string& device() const;
  void set_device(const ::std::string& value);
  void set_device(const char* value);
  void set_device(const char* value, size_t size);
  ::std::string* mutable_device();
  ::std::string* release_device();
  void set_allocated_device(::std::string* device);
  ::std::string* unsafe_arena_release_device();
  void unsafe_arena_set_allocated_device(
      ::std::string* device);

  // optional string container = 2;
  void clear_container();
  static const int kContainerFieldNumber = 2;
  const ::std::string& container() const;
  void set_container(const ::std::string& value);
  void set_container(const char* value);
  void set_container(const char* value, size_t size);
  ::std::string* mutable_container();
  ::std::string* release_container();
  void set_allocated_container(::std::string* container);
  ::std::string* unsafe_arena_release_container();
  void unsafe_arena_set_allocated_container(
      ::std::string* container);

  // optional string name = 3;
  void clear_name();
  static const int kNameFieldNumber = 3;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);
  ::std::string* unsafe_arena_release_name();
  void unsafe_arena_set_allocated_name(
      ::std::string* name);

  // optional uint64 hash_code = 4;
  void clear_hash_code();
  static const int kHashCodeFieldNumber = 4;
  ::google::protobuf::uint64 hash_code() const;
  void set_hash_code(::google::protobuf::uint64 value);

  // optional string maybe_type_name = 5;
  void clear_maybe_type_name();
  static const int kMaybeTypeNameFieldNumber = 5;
  const ::std::string& maybe_type_name() const;
  void set_maybe_type_name(const ::std::string& value);
  void set_maybe_type_name(const char* value);
  void set_maybe_type_name(const char* value, size_t size);
  ::std::string* mutable_maybe_type_name();
  ::std::string* release_maybe_type_name();
  void set_allocated_maybe_type_name(::std::string* maybe_type_name);
  ::std::string* unsafe_arena_release_maybe_type_name();
  void unsafe_arena_set_allocated_maybe_type_name(
      ::std::string* maybe_type_name);

  // repeated .tensorflow.ResourceHandleProto.DtypeAndShape dtypes_and_shapes = 6;
  int dtypes_and_shapes_size() const;
  void clear_dtypes_and_shapes();
  static const int kDtypesAndShapesFieldNumber = 6;
  const ::tensorflow::ResourceHandleProto_DtypeAndShape& dtypes_and_shapes(int index) const;
  ::tensorflow::ResourceHandleProto_DtypeAndShape* mutable_dtypes_and_shapes(int index);
  ::tensorflow::ResourceHandleProto_DtypeAndShape* add_dtypes_and_shapes();
  ::google::protobuf::RepeatedPtrField< ::tensorflow::ResourceHandleProto_DtypeAndShape >*
      mutable_dtypes_and_shapes();
  const ::google::protobuf::RepeatedPtrField< ::tensorflow::ResourceHandleProto_DtypeAndShape >&
      dtypes_and_shapes() const;

  // @@protoc_insertion_point(class_scope:tensorflow.ResourceHandleProto)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  friend class ::google::protobuf::Arena;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr device_;
  ::google::protobuf::internal::ArenaStringPtr container_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::uint64 hash_code_;
  ::google::protobuf::internal::ArenaStringPtr maybe_type_name_;
  ::google::protobuf::RepeatedPtrField< ::tensorflow::ResourceHandleProto_DtypeAndShape > dtypes_and_shapes_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_tensorflow_2ftensorflow_2fcore_2fframework_2fresource_5fhandle_2eproto();
  friend void protobuf_AssignDesc_tensorflow_2ftensorflow_2fcore_2fframework_2fresource_5fhandle_2eproto();
  friend void protobuf_ShutdownFile_tensorflow_2ftensorflow_2fcore_2fframework_2fresource_5fhandle_2eproto();

  void InitAsDefaultInstance();
  static ResourceHandleProto* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// ResourceHandleProto_DtypeAndShape

// optional .tensorflow.DataType dtype = 1;
inline void ResourceHandleProto_DtypeAndShape::clear_dtype() {
  dtype_ = 0;
}
inline ::tensorflow::DataType ResourceHandleProto_DtypeAndShape::dtype() const {
  // @@protoc_insertion_point(field_get:tensorflow.ResourceHandleProto.DtypeAndShape.dtype)
  return static_cast< ::tensorflow::DataType >(dtype_);
}
inline void ResourceHandleProto_DtypeAndShape::set_dtype(::tensorflow::DataType value) {
  
  dtype_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.ResourceHandleProto.DtypeAndShape.dtype)
}

// optional .tensorflow.TensorShapeProto shape = 2;
inline bool ResourceHandleProto_DtypeAndShape::has_shape() const {
  return !_is_default_instance_ && shape_ != NULL;
}
inline void ResourceHandleProto_DtypeAndShape::clear_shape() {
  if (GetArenaNoVirtual() == NULL && shape_ != NULL) delete shape_;
  shape_ = NULL;
}
inline const ::tensorflow::TensorShapeProto& ResourceHandleProto_DtypeAndShape::shape() const {
  // @@protoc_insertion_point(field_get:tensorflow.ResourceHandleProto.DtypeAndShape.shape)
  return shape_ != NULL ? *shape_ : *default_instance_->shape_;
}
inline ::tensorflow::TensorShapeProto* ResourceHandleProto_DtypeAndShape::mutable_shape() {
  
  if (shape_ == NULL) {
    _slow_mutable_shape();
  }
  // @@protoc_insertion_point(field_mutable:tensorflow.ResourceHandleProto.DtypeAndShape.shape)
  return shape_;
}
inline ::tensorflow::TensorShapeProto* ResourceHandleProto_DtypeAndShape::release_shape() {
  // @@protoc_insertion_point(field_release:tensorflow.ResourceHandleProto.DtypeAndShape.shape)
  
  if (GetArenaNoVirtual() != NULL) {
    return _slow_release_shape();
  } else {
    ::tensorflow::TensorShapeProto* temp = shape_;
    shape_ = NULL;
    return temp;
  }
}
inline  void ResourceHandleProto_DtypeAndShape::set_allocated_shape(::tensorflow::TensorShapeProto* shape) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete shape_;
  }
  if (shape != NULL) {
    _slow_set_allocated_shape(message_arena, &shape);
  }
  shape_ = shape;
  if (shape) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:tensorflow.ResourceHandleProto.DtypeAndShape.shape)
}

// -------------------------------------------------------------------

// ResourceHandleProto

// optional string device = 1;
inline void ResourceHandleProto::clear_device() {
  device_.ClearToEmpty(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const ::std::string& ResourceHandleProto::device() const {
  // @@protoc_insertion_point(field_get:tensorflow.ResourceHandleProto.device)
  return device_.Get(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ResourceHandleProto::set_device(const ::std::string& value) {
  
  device_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set:tensorflow.ResourceHandleProto.device)
}
inline void ResourceHandleProto::set_device(const char* value) {
  
  device_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_char:tensorflow.ResourceHandleProto.device)
}
inline void ResourceHandleProto::set_device(const char* value,
    size_t size) {
  
  device_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_pointer:tensorflow.ResourceHandleProto.device)
}
inline ::std::string* ResourceHandleProto::mutable_device() {
  
  // @@protoc_insertion_point(field_mutable:tensorflow.ResourceHandleProto.device)
  return device_.Mutable(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* ResourceHandleProto::release_device() {
  // @@protoc_insertion_point(field_release:tensorflow.ResourceHandleProto.device)
  
  return device_.Release(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* ResourceHandleProto::unsafe_arena_release_device() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.ResourceHandleProto.device)
  GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
  
  return device_.UnsafeArenaRelease(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      GetArenaNoVirtual());
}
inline void ResourceHandleProto::set_allocated_device(::std::string* device) {
  if (device != NULL) {
    
  } else {
    
  }
  device_.SetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), device,
      GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_allocated:tensorflow.ResourceHandleProto.device)
}
inline void ResourceHandleProto::unsafe_arena_set_allocated_device(
    ::std::string* device) {
  GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
  if (device != NULL) {
    
  } else {
    
  }
  device_.UnsafeArenaSetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      device, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.ResourceHandleProto.device)
}

// optional string container = 2;
inline void ResourceHandleProto::clear_container() {
  container_.ClearToEmpty(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const ::std::string& ResourceHandleProto::container() const {
  // @@protoc_insertion_point(field_get:tensorflow.ResourceHandleProto.container)
  return container_.Get(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ResourceHandleProto::set_container(const ::std::string& value) {
  
  container_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set:tensorflow.ResourceHandleProto.container)
}
inline void ResourceHandleProto::set_container(const char* value) {
  
  container_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_char:tensorflow.ResourceHandleProto.container)
}
inline void ResourceHandleProto::set_container(const char* value,
    size_t size) {
  
  container_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_pointer:tensorflow.ResourceHandleProto.container)
}
inline ::std::string* ResourceHandleProto::mutable_container() {
  
  // @@protoc_insertion_point(field_mutable:tensorflow.ResourceHandleProto.container)
  return container_.Mutable(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* ResourceHandleProto::release_container() {
  // @@protoc_insertion_point(field_release:tensorflow.ResourceHandleProto.container)
  
  return container_.Release(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* ResourceHandleProto::unsafe_arena_release_container() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.ResourceHandleProto.container)
  GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
  
  return container_.UnsafeArenaRelease(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      GetArenaNoVirtual());
}
inline void ResourceHandleProto::set_allocated_container(::std::string* container) {
  if (container != NULL) {
    
  } else {
    
  }
  container_.SetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), container,
      GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_allocated:tensorflow.ResourceHandleProto.container)
}
inline void ResourceHandleProto::unsafe_arena_set_allocated_container(
    ::std::string* container) {
  GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
  if (container != NULL) {
    
  } else {
    
  }
  container_.UnsafeArenaSetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      container, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.ResourceHandleProto.container)
}

// optional string name = 3;
inline void ResourceHandleProto::clear_name() {
  name_.ClearToEmpty(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const ::std::string& ResourceHandleProto::name() const {
  // @@protoc_insertion_point(field_get:tensorflow.ResourceHandleProto.name)
  return name_.Get(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ResourceHandleProto::set_name(const ::std::string& value) {
  
  name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set:tensorflow.ResourceHandleProto.name)
}
inline void ResourceHandleProto::set_name(const char* value) {
  
  name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_char:tensorflow.ResourceHandleProto.name)
}
inline void ResourceHandleProto::set_name(const char* value,
    size_t size) {
  
  name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_pointer:tensorflow.ResourceHandleProto.name)
}
inline ::std::string* ResourceHandleProto::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:tensorflow.ResourceHandleProto.name)
  return name_.Mutable(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* ResourceHandleProto::release_name() {
  // @@protoc_insertion_point(field_release:tensorflow.ResourceHandleProto.name)
  
  return name_.Release(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* ResourceHandleProto::unsafe_arena_release_name() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.ResourceHandleProto.name)
  GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
  
  return name_.UnsafeArenaRelease(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      GetArenaNoVirtual());
}
inline void ResourceHandleProto::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_allocated:tensorflow.ResourceHandleProto.name)
}
inline void ResourceHandleProto::unsafe_arena_set_allocated_name(
    ::std::string* name) {
  GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
  if (name != NULL) {
    
  } else {
    
  }
  name_.UnsafeArenaSetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      name, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.ResourceHandleProto.name)
}

// optional uint64 hash_code = 4;
inline void ResourceHandleProto::clear_hash_code() {
  hash_code_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 ResourceHandleProto::hash_code() const {
  // @@protoc_insertion_point(field_get:tensorflow.ResourceHandleProto.hash_code)
  return hash_code_;
}
inline void ResourceHandleProto::set_hash_code(::google::protobuf::uint64 value) {
  
  hash_code_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.ResourceHandleProto.hash_code)
}

// optional string maybe_type_name = 5;
inline void ResourceHandleProto::clear_maybe_type_name() {
  maybe_type_name_.ClearToEmpty(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const ::std::string& ResourceHandleProto::maybe_type_name() const {
  // @@protoc_insertion_point(field_get:tensorflow.ResourceHandleProto.maybe_type_name)
  return maybe_type_name_.Get(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ResourceHandleProto::set_maybe_type_name(const ::std::string& value) {
  
  maybe_type_name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set:tensorflow.ResourceHandleProto.maybe_type_name)
}
inline void ResourceHandleProto::set_maybe_type_name(const char* value) {
  
  maybe_type_name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_char:tensorflow.ResourceHandleProto.maybe_type_name)
}
inline void ResourceHandleProto::set_maybe_type_name(const char* value,
    size_t size) {
  
  maybe_type_name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_pointer:tensorflow.ResourceHandleProto.maybe_type_name)
}
inline ::std::string* ResourceHandleProto::mutable_maybe_type_name() {
  
  // @@protoc_insertion_point(field_mutable:tensorflow.ResourceHandleProto.maybe_type_name)
  return maybe_type_name_.Mutable(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* ResourceHandleProto::release_maybe_type_name() {
  // @@protoc_insertion_point(field_release:tensorflow.ResourceHandleProto.maybe_type_name)
  
  return maybe_type_name_.Release(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* ResourceHandleProto::unsafe_arena_release_maybe_type_name() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.ResourceHandleProto.maybe_type_name)
  GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
  
  return maybe_type_name_.UnsafeArenaRelease(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      GetArenaNoVirtual());
}
inline void ResourceHandleProto::set_allocated_maybe_type_name(::std::string* maybe_type_name) {
  if (maybe_type_name != NULL) {
    
  } else {
    
  }
  maybe_type_name_.SetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), maybe_type_name,
      GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_allocated:tensorflow.ResourceHandleProto.maybe_type_name)
}
inline void ResourceHandleProto::unsafe_arena_set_allocated_maybe_type_name(
    ::std::string* maybe_type_name) {
  GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
  if (maybe_type_name != NULL) {
    
  } else {
    
  }
  maybe_type_name_.UnsafeArenaSetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      maybe_type_name, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.ResourceHandleProto.maybe_type_name)
}

// repeated .tensorflow.ResourceHandleProto.DtypeAndShape dtypes_and_shapes = 6;
inline int ResourceHandleProto::dtypes_and_shapes_size() const {
  return dtypes_and_shapes_.size();
}
inline void ResourceHandleProto::clear_dtypes_and_shapes() {
  dtypes_and_shapes_.Clear();
}
inline const ::tensorflow::ResourceHandleProto_DtypeAndShape& ResourceHandleProto::dtypes_and_shapes(int index) const {
  // @@protoc_insertion_point(field_get:tensorflow.ResourceHandleProto.dtypes_and_shapes)
  return dtypes_and_shapes_.Get(index);
}
inline ::tensorflow::ResourceHandleProto_DtypeAndShape* ResourceHandleProto::mutable_dtypes_and_shapes(int index) {
  // @@protoc_insertion_point(field_mutable:tensorflow.ResourceHandleProto.dtypes_and_shapes)
  return dtypes_and_shapes_.Mutable(index);
}
inline ::tensorflow::ResourceHandleProto_DtypeAndShape* ResourceHandleProto::add_dtypes_and_shapes() {
  // @@protoc_insertion_point(field_add:tensorflow.ResourceHandleProto.dtypes_and_shapes)
  return dtypes_and_shapes_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::tensorflow::ResourceHandleProto_DtypeAndShape >*
ResourceHandleProto::mutable_dtypes_and_shapes() {
  // @@protoc_insertion_point(field_mutable_list:tensorflow.ResourceHandleProto.dtypes_and_shapes)
  return &dtypes_and_shapes_;
}
inline const ::google::protobuf::RepeatedPtrField< ::tensorflow::ResourceHandleProto_DtypeAndShape >&
ResourceHandleProto::dtypes_and_shapes() const {
  // @@protoc_insertion_point(field_list:tensorflow.ResourceHandleProto.dtypes_and_shapes)
  return dtypes_and_shapes_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace tensorflow

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_tensorflow_2ftensorflow_2fcore_2fframework_2fresource_5fhandle_2eproto__INCLUDED
