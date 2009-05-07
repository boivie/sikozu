// Generated by the protocol buffer compiler.  DO NOT EDIT!

#include "core.pb.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format_inl.h>

namespace {

const ::google::protobuf::Descriptor* Contact_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Contact_reflection_ = NULL;
const ::google::protobuf::Descriptor* PingRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PingRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* PingResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PingResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* FindNodeRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  FindNodeRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* FindNodeResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  FindNodeResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* QueryServicesRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  QueryServicesRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* QueryServicesResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  QueryServicesResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetServicesRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetServicesRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetServicesResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetServicesResponse_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* BaseService_descriptor_ = NULL;

}  // namespace


void protobuf_BuildDesc_core_2eproto_AssignGlobalDescriptors(const ::google::protobuf::FileDescriptor* file) {
  Contact_descriptor_ = file->message_type(0);
  Contact::default_instance_ = new Contact();
  static const int Contact_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Contact, nid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Contact, ipv4_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Contact, ipv6_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Contact, port_),
  };
  Contact_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Contact_descriptor_,
      Contact::default_instance_,
      Contact_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Contact, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Contact, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(Contact));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Contact_descriptor_, Contact::default_instance_);
  PingRequest_descriptor_ = file->message_type(1);
  PingRequest::default_instance_ = new PingRequest();
  static const int PingRequest_offsets_[1] = {
  };
  PingRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      PingRequest_descriptor_,
      PingRequest::default_instance_,
      PingRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PingRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PingRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(PingRequest));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    PingRequest_descriptor_, PingRequest::default_instance_);
  PingResponse_descriptor_ = file->message_type(2);
  PingResponse::default_instance_ = new PingResponse();
  static const int PingResponse_offsets_[1] = {
  };
  PingResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      PingResponse_descriptor_,
      PingResponse::default_instance_,
      PingResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PingResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PingResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(PingResponse));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    PingResponse_descriptor_, PingResponse::default_instance_);
  FindNodeRequest_descriptor_ = file->message_type(3);
  FindNodeRequest::default_instance_ = new FindNodeRequest();
  static const int FindNodeRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FindNodeRequest, nid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FindNodeRequest, service_),
  };
  FindNodeRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      FindNodeRequest_descriptor_,
      FindNodeRequest::default_instance_,
      FindNodeRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FindNodeRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FindNodeRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(FindNodeRequest));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    FindNodeRequest_descriptor_, FindNodeRequest::default_instance_);
  FindNodeResponse_descriptor_ = file->message_type(4);
  FindNodeResponse::default_instance_ = new FindNodeResponse();
  static const int FindNodeResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FindNodeResponse, contacts_),
  };
  FindNodeResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      FindNodeResponse_descriptor_,
      FindNodeResponse::default_instance_,
      FindNodeResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FindNodeResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FindNodeResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(FindNodeResponse));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    FindNodeResponse_descriptor_, FindNodeResponse::default_instance_);
  QueryServicesRequest_descriptor_ = file->message_type(5);
  QueryServicesRequest::default_instance_ = new QueryServicesRequest();
  static const int QueryServicesRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryServicesRequest, service_),
  };
  QueryServicesRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      QueryServicesRequest_descriptor_,
      QueryServicesRequest::default_instance_,
      QueryServicesRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryServicesRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryServicesRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(QueryServicesRequest));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    QueryServicesRequest_descriptor_, QueryServicesRequest::default_instance_);
  QueryServicesResponse_descriptor_ = file->message_type(6);
  QueryServicesResponse::default_instance_ = new QueryServicesResponse();
  static const int QueryServicesResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryServicesResponse, present_),
  };
  QueryServicesResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      QueryServicesResponse_descriptor_,
      QueryServicesResponse::default_instance_,
      QueryServicesResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryServicesResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QueryServicesResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(QueryServicesResponse));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    QueryServicesResponse_descriptor_, QueryServicesResponse::default_instance_);
  GetServicesRequest_descriptor_ = file->message_type(7);
  GetServicesRequest::default_instance_ = new GetServicesRequest();
  static const int GetServicesRequest_offsets_[1] = {
  };
  GetServicesRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetServicesRequest_descriptor_,
      GetServicesRequest::default_instance_,
      GetServicesRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetServicesRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetServicesRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(GetServicesRequest));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetServicesRequest_descriptor_, GetServicesRequest::default_instance_);
  GetServicesResponse_descriptor_ = file->message_type(8);
  GetServicesResponse::default_instance_ = new GetServicesResponse();
  static const int GetServicesResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetServicesResponse, services_),
  };
  GetServicesResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetServicesResponse_descriptor_,
      GetServicesResponse::default_instance_,
      GetServicesResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetServicesResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetServicesResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(GetServicesResponse));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetServicesResponse_descriptor_, GetServicesResponse::default_instance_);
  BaseService_descriptor_ = file->service(0);
  Contact::default_instance_->InitAsDefaultInstance();
  PingRequest::default_instance_->InitAsDefaultInstance();
  PingResponse::default_instance_->InitAsDefaultInstance();
  FindNodeRequest::default_instance_->InitAsDefaultInstance();
  FindNodeResponse::default_instance_->InitAsDefaultInstance();
  QueryServicesRequest::default_instance_->InitAsDefaultInstance();
  QueryServicesResponse::default_instance_->InitAsDefaultInstance();
  GetServicesRequest::default_instance_->InitAsDefaultInstance();
  GetServicesResponse::default_instance_->InitAsDefaultInstance();
}

void protobuf_BuildDesc_core_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  ::google::protobuf::DescriptorPool* pool =
    ::google::protobuf::DescriptorPool::internal_generated_pool();

  pool->InternalBuildGeneratedFile(
    "\n\ncore.proto\"@\n\007Contact\022\013\n\003nid\030\001 \002(\014\022\014\n\004"
    "ipv4\030\002 \001(\r\022\014\n\004ipv6\030\003 \001(\014\022\014\n\004port\030\004 \002(\r\"\r"
    "\n\013PingRequest\"\016\n\014PingResponse\"/\n\017FindNod"
    "eRequest\022\013\n\003nid\030\001 \002(\014\022\017\n\007service\030\002 \001(\t\"."
    "\n\020FindNodeResponse\022\032\n\010contacts\030\001 \003(\0132\010.C"
    "ontact\"\'\n\024QueryServicesRequest\022\017\n\007servic"
    "e\030\001 \003(\t\"(\n\025QueryServicesResponse\022\017\n\007pres"
    "ent\030\001 \003(\r\"\024\n\022GetServicesRequest\"\'\n\023GetSe"
    "rvicesResponse\022\020\n\010services\030\001 \003(\t2\335\001\n\013Bas"
    "eService\022#\n\004Ping\022\014.PingRequest\032\r.PingRes"
    "ponse\022/\n\010FindNode\022\020.FindNodeRequest\032\021.Fi"
    "ndNodeResponse\022>\n\rQueryServices\022\025.QueryS"
    "ervicesRequest\032\026.QueryServicesResponse\0228"
    "\n\013GetServices\022\023.GetServicesRequest\032\024.Get"
    "ServicesResponse", 576,
  &protobuf_BuildDesc_core_2eproto_AssignGlobalDescriptors);
}

// Force BuildDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_core_2eproto {
  StaticDescriptorInitializer_core_2eproto() {
    protobuf_BuildDesc_core_2eproto();
  }
} static_descriptor_initializer_core_2eproto_;


// ===================================================================

const ::std::string Contact::_default_nid_;

const ::std::string Contact::_default_ipv6_;

Contact::Contact()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    nid_(const_cast< ::std::string*>(&_default_nid_)),
    ipv4_(0u),
    ipv6_(const_cast< ::std::string*>(&_default_ipv6_)),
    port_(0u) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void Contact::InitAsDefaultInstance() {}

Contact::Contact(const Contact& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    nid_(const_cast< ::std::string*>(&_default_nid_)),
    ipv4_(0u),
    ipv6_(const_cast< ::std::string*>(&_default_ipv6_)),
    port_(0u) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

Contact::~Contact() {
  if (nid_ != &_default_nid_) {
    delete nid_;
  }
  if (ipv6_ != &_default_ipv6_) {
    delete ipv6_;
  }
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* Contact::descriptor() {
  if (Contact_descriptor_ == NULL) protobuf_BuildDesc_core_2eproto();
  return Contact_descriptor_;
}

const Contact& Contact::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_core_2eproto();
  return *default_instance_;
}

Contact* Contact::default_instance_ = NULL;

Contact* Contact::New() const {
  return new Contact;
}

const ::google::protobuf::Descriptor* Contact::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* Contact::GetReflection() const {
  if (Contact_reflection_ == NULL) protobuf_BuildDesc_core_2eproto();
  return Contact_reflection_;
}

// ===================================================================

PingRequest::PingRequest()
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void PingRequest::InitAsDefaultInstance() {}

PingRequest::PingRequest(const PingRequest& from)
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

PingRequest::~PingRequest() {
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* PingRequest::descriptor() {
  if (PingRequest_descriptor_ == NULL) protobuf_BuildDesc_core_2eproto();
  return PingRequest_descriptor_;
}

const PingRequest& PingRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_core_2eproto();
  return *default_instance_;
}

PingRequest* PingRequest::default_instance_ = NULL;

PingRequest* PingRequest::New() const {
  return new PingRequest;
}

const ::google::protobuf::Descriptor* PingRequest::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* PingRequest::GetReflection() const {
  if (PingRequest_reflection_ == NULL) protobuf_BuildDesc_core_2eproto();
  return PingRequest_reflection_;
}

// ===================================================================

PingResponse::PingResponse()
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void PingResponse::InitAsDefaultInstance() {}

PingResponse::PingResponse(const PingResponse& from)
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

PingResponse::~PingResponse() {
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* PingResponse::descriptor() {
  if (PingResponse_descriptor_ == NULL) protobuf_BuildDesc_core_2eproto();
  return PingResponse_descriptor_;
}

const PingResponse& PingResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_core_2eproto();
  return *default_instance_;
}

PingResponse* PingResponse::default_instance_ = NULL;

PingResponse* PingResponse::New() const {
  return new PingResponse;
}

const ::google::protobuf::Descriptor* PingResponse::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* PingResponse::GetReflection() const {
  if (PingResponse_reflection_ == NULL) protobuf_BuildDesc_core_2eproto();
  return PingResponse_reflection_;
}

// ===================================================================

const ::std::string FindNodeRequest::_default_nid_;
const ::std::string FindNodeRequest::_default_service_;
FindNodeRequest::FindNodeRequest()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    nid_(const_cast< ::std::string*>(&_default_nid_)),
    service_(const_cast< ::std::string*>(&_default_service_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void FindNodeRequest::InitAsDefaultInstance() {}

FindNodeRequest::FindNodeRequest(const FindNodeRequest& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    nid_(const_cast< ::std::string*>(&_default_nid_)),
    service_(const_cast< ::std::string*>(&_default_service_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

FindNodeRequest::~FindNodeRequest() {
  if (nid_ != &_default_nid_) {
    delete nid_;
  }
  if (service_ != &_default_service_) {
    delete service_;
  }
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* FindNodeRequest::descriptor() {
  if (FindNodeRequest_descriptor_ == NULL) protobuf_BuildDesc_core_2eproto();
  return FindNodeRequest_descriptor_;
}

const FindNodeRequest& FindNodeRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_core_2eproto();
  return *default_instance_;
}

FindNodeRequest* FindNodeRequest::default_instance_ = NULL;

FindNodeRequest* FindNodeRequest::New() const {
  return new FindNodeRequest;
}

const ::google::protobuf::Descriptor* FindNodeRequest::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* FindNodeRequest::GetReflection() const {
  if (FindNodeRequest_reflection_ == NULL) protobuf_BuildDesc_core_2eproto();
  return FindNodeRequest_reflection_;
}

// ===================================================================


FindNodeResponse::FindNodeResponse()
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void FindNodeResponse::InitAsDefaultInstance() {}

FindNodeResponse::FindNodeResponse(const FindNodeResponse& from)
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

FindNodeResponse::~FindNodeResponse() {
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* FindNodeResponse::descriptor() {
  if (FindNodeResponse_descriptor_ == NULL) protobuf_BuildDesc_core_2eproto();
  return FindNodeResponse_descriptor_;
}

const FindNodeResponse& FindNodeResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_core_2eproto();
  return *default_instance_;
}

FindNodeResponse* FindNodeResponse::default_instance_ = NULL;

FindNodeResponse* FindNodeResponse::New() const {
  return new FindNodeResponse;
}

const ::google::protobuf::Descriptor* FindNodeResponse::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* FindNodeResponse::GetReflection() const {
  if (FindNodeResponse_reflection_ == NULL) protobuf_BuildDesc_core_2eproto();
  return FindNodeResponse_reflection_;
}

// ===================================================================


QueryServicesRequest::QueryServicesRequest()
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void QueryServicesRequest::InitAsDefaultInstance() {}

QueryServicesRequest::QueryServicesRequest(const QueryServicesRequest& from)
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

QueryServicesRequest::~QueryServicesRequest() {
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* QueryServicesRequest::descriptor() {
  if (QueryServicesRequest_descriptor_ == NULL) protobuf_BuildDesc_core_2eproto();
  return QueryServicesRequest_descriptor_;
}

const QueryServicesRequest& QueryServicesRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_core_2eproto();
  return *default_instance_;
}

QueryServicesRequest* QueryServicesRequest::default_instance_ = NULL;

QueryServicesRequest* QueryServicesRequest::New() const {
  return new QueryServicesRequest;
}

const ::google::protobuf::Descriptor* QueryServicesRequest::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* QueryServicesRequest::GetReflection() const {
  if (QueryServicesRequest_reflection_ == NULL) protobuf_BuildDesc_core_2eproto();
  return QueryServicesRequest_reflection_;
}

// ===================================================================


QueryServicesResponse::QueryServicesResponse()
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void QueryServicesResponse::InitAsDefaultInstance() {}

QueryServicesResponse::QueryServicesResponse(const QueryServicesResponse& from)
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

QueryServicesResponse::~QueryServicesResponse() {
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* QueryServicesResponse::descriptor() {
  if (QueryServicesResponse_descriptor_ == NULL) protobuf_BuildDesc_core_2eproto();
  return QueryServicesResponse_descriptor_;
}

const QueryServicesResponse& QueryServicesResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_core_2eproto();
  return *default_instance_;
}

QueryServicesResponse* QueryServicesResponse::default_instance_ = NULL;

QueryServicesResponse* QueryServicesResponse::New() const {
  return new QueryServicesResponse;
}

const ::google::protobuf::Descriptor* QueryServicesResponse::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* QueryServicesResponse::GetReflection() const {
  if (QueryServicesResponse_reflection_ == NULL) protobuf_BuildDesc_core_2eproto();
  return QueryServicesResponse_reflection_;
}

// ===================================================================

GetServicesRequest::GetServicesRequest()
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void GetServicesRequest::InitAsDefaultInstance() {}

GetServicesRequest::GetServicesRequest(const GetServicesRequest& from)
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

GetServicesRequest::~GetServicesRequest() {
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* GetServicesRequest::descriptor() {
  if (GetServicesRequest_descriptor_ == NULL) protobuf_BuildDesc_core_2eproto();
  return GetServicesRequest_descriptor_;
}

const GetServicesRequest& GetServicesRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_core_2eproto();
  return *default_instance_;
}

GetServicesRequest* GetServicesRequest::default_instance_ = NULL;

GetServicesRequest* GetServicesRequest::New() const {
  return new GetServicesRequest;
}

const ::google::protobuf::Descriptor* GetServicesRequest::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* GetServicesRequest::GetReflection() const {
  if (GetServicesRequest_reflection_ == NULL) protobuf_BuildDesc_core_2eproto();
  return GetServicesRequest_reflection_;
}

// ===================================================================


GetServicesResponse::GetServicesResponse()
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void GetServicesResponse::InitAsDefaultInstance() {}

GetServicesResponse::GetServicesResponse(const GetServicesResponse& from)
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

GetServicesResponse::~GetServicesResponse() {
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* GetServicesResponse::descriptor() {
  if (GetServicesResponse_descriptor_ == NULL) protobuf_BuildDesc_core_2eproto();
  return GetServicesResponse_descriptor_;
}

const GetServicesResponse& GetServicesResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_core_2eproto();
  return *default_instance_;
}

GetServicesResponse* GetServicesResponse::default_instance_ = NULL;

GetServicesResponse* GetServicesResponse::New() const {
  return new GetServicesResponse;
}

const ::google::protobuf::Descriptor* GetServicesResponse::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* GetServicesResponse::GetReflection() const {
  if (GetServicesResponse_reflection_ == NULL) protobuf_BuildDesc_core_2eproto();
  return GetServicesResponse_reflection_;
}

// ===================================================================

BaseService::~BaseService() {}

const ::google::protobuf::ServiceDescriptor* BaseService::descriptor() {
  return BaseService_descriptor_;
}

const ::google::protobuf::ServiceDescriptor* BaseService::GetDescriptor() {
  return BaseService_descriptor_;
}

void BaseService::Ping(::google::protobuf::RpcController* controller,
                         const ::PingRequest*,
                         ::PingResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Ping() not implemented.");
  done->Run();
}

void BaseService::FindNode(::google::protobuf::RpcController* controller,
                         const ::FindNodeRequest*,
                         ::FindNodeResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method FindNode() not implemented.");
  done->Run();
}

void BaseService::QueryServices(::google::protobuf::RpcController* controller,
                         const ::QueryServicesRequest*,
                         ::QueryServicesResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method QueryServices() not implemented.");
  done->Run();
}

void BaseService::GetServices(::google::protobuf::RpcController* controller,
                         const ::GetServicesRequest*,
                         ::GetServicesResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method GetServices() not implemented.");
  done->Run();
}

void BaseService::CallMethod(const ::google::protobuf::MethodDescriptor* method,
                             ::google::protobuf::RpcController* controller,
                             const ::google::protobuf::Message* request,
                             ::google::protobuf::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), BaseService_descriptor_);
  switch(method->index()) {
    case 0:
      Ping(controller,
             ::google::protobuf::down_cast<const ::PingRequest*>(request),
             ::google::protobuf::down_cast< ::PingResponse*>(response),
             done);
      break;
    case 1:
      FindNode(controller,
             ::google::protobuf::down_cast<const ::FindNodeRequest*>(request),
             ::google::protobuf::down_cast< ::FindNodeResponse*>(response),
             done);
      break;
    case 2:
      QueryServices(controller,
             ::google::protobuf::down_cast<const ::QueryServicesRequest*>(request),
             ::google::protobuf::down_cast< ::QueryServicesResponse*>(response),
             done);
      break;
    case 3:
      GetServices(controller,
             ::google::protobuf::down_cast<const ::GetServicesRequest*>(request),
             ::google::protobuf::down_cast< ::GetServicesResponse*>(response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::google::protobuf::Message& BaseService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), BaseService_descriptor_);
  switch(method->index()) {
    case 0:
      return ::PingRequest::default_instance();
    case 1:
      return ::FindNodeRequest::default_instance();
    case 2:
      return ::QueryServicesRequest::default_instance();
    case 3:
      return ::GetServicesRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

const ::google::protobuf::Message& BaseService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), BaseService_descriptor_);
  switch(method->index()) {
    case 0:
      return ::PingResponse::default_instance();
    case 1:
      return ::FindNodeResponse::default_instance();
    case 2:
      return ::QueryServicesResponse::default_instance();
    case 3:
      return ::GetServicesResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

BaseService_Stub::BaseService_Stub(::google::protobuf::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
BaseService_Stub::BaseService_Stub(
    ::google::protobuf::RpcChannel* channel,
    ::google::protobuf::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::google::protobuf::Service::STUB_OWNS_CHANNEL) {}
BaseService_Stub::~BaseService_Stub() {
  if (owns_channel_) delete channel_;
}

void BaseService_Stub::Ping(::google::protobuf::RpcController* controller,
                              const ::PingRequest* request,
                              ::PingResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(BaseService_descriptor_->method(0),
                       controller, request, response, done);
}
void BaseService_Stub::FindNode(::google::protobuf::RpcController* controller,
                              const ::FindNodeRequest* request,
                              ::FindNodeResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(BaseService_descriptor_->method(1),
                       controller, request, response, done);
}
void BaseService_Stub::QueryServices(::google::protobuf::RpcController* controller,
                              const ::QueryServicesRequest* request,
                              ::QueryServicesResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(BaseService_descriptor_->method(2),
                       controller, request, response, done);
}
void BaseService_Stub::GetServices(::google::protobuf::RpcController* controller,
                              const ::GetServicesRequest* request,
                              ::GetServicesResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(BaseService_descriptor_->method(3),
                       controller, request, response, done);
}