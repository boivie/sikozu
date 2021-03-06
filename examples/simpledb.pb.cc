// Generated by the protocol buffer compiler.  DO NOT EDIT!

#include "simpledb.pb.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format_inl.h>

namespace Sikozu {
namespace SimpleDb {
namespace Messages {

namespace {

const ::google::protobuf::Descriptor* PutRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PutRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* PutResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PutResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* DeleteRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  DeleteRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* DeleteResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  DeleteResponse_reflection_ = NULL;

}  // namespace


void protobuf_BuildDesc_simpledb_2eproto_AssignGlobalDescriptors(const ::google::protobuf::FileDescriptor* file) {
  PutRequest_descriptor_ = file->message_type(0);
  PutRequest::default_instance_ = new PutRequest();
  static const int PutRequest_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PutRequest, key_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PutRequest, value_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PutRequest, ttl_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PutRequest, secret_hash_),
  };
  PutRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      PutRequest_descriptor_,
      PutRequest::default_instance_,
      PutRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PutRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PutRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(PutRequest));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    PutRequest_descriptor_, PutRequest::default_instance_);
  PutResponse_descriptor_ = file->message_type(1);
  PutResponse::default_instance_ = new PutResponse();
  static const int PutResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PutResponse, success_),
  };
  PutResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      PutResponse_descriptor_,
      PutResponse::default_instance_,
      PutResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PutResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PutResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(PutResponse));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    PutResponse_descriptor_, PutResponse::default_instance_);
  GetRequest_descriptor_ = file->message_type(2);
  GetRequest::default_instance_ = new GetRequest();
  static const int GetRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetRequest, key_),
  };
  GetRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetRequest_descriptor_,
      GetRequest::default_instance_,
      GetRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(GetRequest));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetRequest_descriptor_, GetRequest::default_instance_);
  GetResponse_descriptor_ = file->message_type(3);
  GetResponse::default_instance_ = new GetResponse();
  static const int GetResponse_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetResponse, success_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetResponse, value_),
  };
  GetResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetResponse_descriptor_,
      GetResponse::default_instance_,
      GetResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(GetResponse));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetResponse_descriptor_, GetResponse::default_instance_);
  DeleteRequest_descriptor_ = file->message_type(4);
  DeleteRequest::default_instance_ = new DeleteRequest();
  static const int DeleteRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeleteRequest, key_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeleteRequest, secret_),
  };
  DeleteRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      DeleteRequest_descriptor_,
      DeleteRequest::default_instance_,
      DeleteRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeleteRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeleteRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(DeleteRequest));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    DeleteRequest_descriptor_, DeleteRequest::default_instance_);
  DeleteResponse_descriptor_ = file->message_type(5);
  DeleteResponse::default_instance_ = new DeleteResponse();
  static const int DeleteResponse_offsets_[1] = {
  };
  DeleteResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      DeleteResponse_descriptor_,
      DeleteResponse::default_instance_,
      DeleteResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeleteResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DeleteResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(DeleteResponse));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    DeleteResponse_descriptor_, DeleteResponse::default_instance_);
  PutRequest::default_instance_->InitAsDefaultInstance();
  PutResponse::default_instance_->InitAsDefaultInstance();
  GetRequest::default_instance_->InitAsDefaultInstance();
  GetResponse::default_instance_->InitAsDefaultInstance();
  DeleteRequest::default_instance_->InitAsDefaultInstance();
  DeleteResponse::default_instance_->InitAsDefaultInstance();
}

void protobuf_BuildDesc_simpledb_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  ::google::protobuf::DescriptorPool* pool =
    ::google::protobuf::DescriptorPool::internal_generated_pool();

  pool->InternalBuildGeneratedFile(
    "\n\016simpledb.proto\022\030Sikozu.SimpleDb.Messag"
    "es\"J\n\nPutRequest\022\013\n\003key\030\001 \002(\t\022\r\n\005value\030\002"
    " \002(\014\022\013\n\003ttl\030\003 \001(\r\022\023\n\013secret_hash\030\004 \001(\014\"$"
    "\n\013PutResponse\022\025\n\007success\030\001 \002(\010:\004true\"\031\n\n"
    "GetRequest\022\013\n\003key\030\001 \002(\t\"3\n\013GetResponse\022\025"
    "\n\007success\030\001 \002(\010:\004true\022\r\n\005value\030\002 \001(\014\",\n\r"
    "DeleteRequest\022\013\n\003key\030\001 \002(\t\022\016\n\006secret\030\002 \002"
    "(\014\"\020\n\016DeleteResponse", 300,
  &protobuf_BuildDesc_simpledb_2eproto_AssignGlobalDescriptors);
}

// Force BuildDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_simpledb_2eproto {
  StaticDescriptorInitializer_simpledb_2eproto() {
    protobuf_BuildDesc_simpledb_2eproto();
  }
} static_descriptor_initializer_simpledb_2eproto_;


// ===================================================================

const ::std::string PutRequest::_default_key_;
const ::std::string PutRequest::_default_value_;

const ::std::string PutRequest::_default_secret_hash_;
PutRequest::PutRequest()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    key_(const_cast< ::std::string*>(&_default_key_)),
    value_(const_cast< ::std::string*>(&_default_value_)),
    ttl_(0u),
    secret_hash_(const_cast< ::std::string*>(&_default_secret_hash_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void PutRequest::InitAsDefaultInstance() {}

PutRequest::PutRequest(const PutRequest& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    key_(const_cast< ::std::string*>(&_default_key_)),
    value_(const_cast< ::std::string*>(&_default_value_)),
    ttl_(0u),
    secret_hash_(const_cast< ::std::string*>(&_default_secret_hash_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

PutRequest::~PutRequest() {
  if (key_ != &_default_key_) {
    delete key_;
  }
  if (value_ != &_default_value_) {
    delete value_;
  }
  if (secret_hash_ != &_default_secret_hash_) {
    delete secret_hash_;
  }
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* PutRequest::descriptor() {
  if (PutRequest_descriptor_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return PutRequest_descriptor_;
}

const PutRequest& PutRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return *default_instance_;
}

PutRequest* PutRequest::default_instance_ = NULL;

PutRequest* PutRequest::New() const {
  return new PutRequest;
}

const ::google::protobuf::Descriptor* PutRequest::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* PutRequest::GetReflection() const {
  if (PutRequest_reflection_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return PutRequest_reflection_;
}

// ===================================================================


PutResponse::PutResponse()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    success_(true) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void PutResponse::InitAsDefaultInstance() {}

PutResponse::PutResponse(const PutResponse& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    success_(true) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

PutResponse::~PutResponse() {
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* PutResponse::descriptor() {
  if (PutResponse_descriptor_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return PutResponse_descriptor_;
}

const PutResponse& PutResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return *default_instance_;
}

PutResponse* PutResponse::default_instance_ = NULL;

PutResponse* PutResponse::New() const {
  return new PutResponse;
}

const ::google::protobuf::Descriptor* PutResponse::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* PutResponse::GetReflection() const {
  if (PutResponse_reflection_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return PutResponse_reflection_;
}

// ===================================================================

const ::std::string GetRequest::_default_key_;
GetRequest::GetRequest()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    key_(const_cast< ::std::string*>(&_default_key_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void GetRequest::InitAsDefaultInstance() {}

GetRequest::GetRequest(const GetRequest& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    key_(const_cast< ::std::string*>(&_default_key_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

GetRequest::~GetRequest() {
  if (key_ != &_default_key_) {
    delete key_;
  }
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* GetRequest::descriptor() {
  if (GetRequest_descriptor_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return GetRequest_descriptor_;
}

const GetRequest& GetRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return *default_instance_;
}

GetRequest* GetRequest::default_instance_ = NULL;

GetRequest* GetRequest::New() const {
  return new GetRequest;
}

const ::google::protobuf::Descriptor* GetRequest::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* GetRequest::GetReflection() const {
  if (GetRequest_reflection_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return GetRequest_reflection_;
}

// ===================================================================


const ::std::string GetResponse::_default_value_;
GetResponse::GetResponse()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    success_(true),
    value_(const_cast< ::std::string*>(&_default_value_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void GetResponse::InitAsDefaultInstance() {}

GetResponse::GetResponse(const GetResponse& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    success_(true),
    value_(const_cast< ::std::string*>(&_default_value_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

GetResponse::~GetResponse() {
  if (value_ != &_default_value_) {
    delete value_;
  }
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* GetResponse::descriptor() {
  if (GetResponse_descriptor_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return GetResponse_descriptor_;
}

const GetResponse& GetResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return *default_instance_;
}

GetResponse* GetResponse::default_instance_ = NULL;

GetResponse* GetResponse::New() const {
  return new GetResponse;
}

const ::google::protobuf::Descriptor* GetResponse::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* GetResponse::GetReflection() const {
  if (GetResponse_reflection_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return GetResponse_reflection_;
}

// ===================================================================

const ::std::string DeleteRequest::_default_key_;
const ::std::string DeleteRequest::_default_secret_;
DeleteRequest::DeleteRequest()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    key_(const_cast< ::std::string*>(&_default_key_)),
    secret_(const_cast< ::std::string*>(&_default_secret_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void DeleteRequest::InitAsDefaultInstance() {}

DeleteRequest::DeleteRequest(const DeleteRequest& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    key_(const_cast< ::std::string*>(&_default_key_)),
    secret_(const_cast< ::std::string*>(&_default_secret_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

DeleteRequest::~DeleteRequest() {
  if (key_ != &_default_key_) {
    delete key_;
  }
  if (secret_ != &_default_secret_) {
    delete secret_;
  }
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* DeleteRequest::descriptor() {
  if (DeleteRequest_descriptor_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return DeleteRequest_descriptor_;
}

const DeleteRequest& DeleteRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return *default_instance_;
}

DeleteRequest* DeleteRequest::default_instance_ = NULL;

DeleteRequest* DeleteRequest::New() const {
  return new DeleteRequest;
}

const ::google::protobuf::Descriptor* DeleteRequest::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* DeleteRequest::GetReflection() const {
  if (DeleteRequest_reflection_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return DeleteRequest_reflection_;
}

// ===================================================================

DeleteResponse::DeleteResponse()
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void DeleteResponse::InitAsDefaultInstance() {}

DeleteResponse::DeleteResponse(const DeleteResponse& from)
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

DeleteResponse::~DeleteResponse() {
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* DeleteResponse::descriptor() {
  if (DeleteResponse_descriptor_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return DeleteResponse_descriptor_;
}

const DeleteResponse& DeleteResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return *default_instance_;
}

DeleteResponse* DeleteResponse::default_instance_ = NULL;

DeleteResponse* DeleteResponse::New() const {
  return new DeleteResponse;
}

const ::google::protobuf::Descriptor* DeleteResponse::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* DeleteResponse::GetReflection() const {
  if (DeleteResponse_reflection_ == NULL) protobuf_BuildDesc_simpledb_2eproto();
  return DeleteResponse_reflection_;
}

}  // namespace Messages
}  // namespace SimpleDb
}  // namespace Sikozu
