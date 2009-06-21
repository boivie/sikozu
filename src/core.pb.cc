// Generated by the protocol buffer compiler.  DO NOT EDIT!

#include "core.pb.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format_inl.h>

namespace Sikozu {
namespace Messages {

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
const ::google::protobuf::Descriptor* HelloRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HelloRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* HelloResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HelloResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* FindNodeRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  FindNodeRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* FindNodeResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  FindNodeResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetServicesRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetServicesRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetServicesResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetServicesResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetServicesResponse_Result_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetServicesResponse_Result_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetChannelRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetChannelRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* GetChannelResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GetChannelResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* AnnounceServiceRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AnnounceServiceRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* AnnounceServiceResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AnnounceServiceResponse_reflection_ = NULL;

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
  HelloRequest_descriptor_ = file->message_type(3);
  HelloRequest::default_instance_ = new HelloRequest();
  static const int HelloRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HelloRequest, nid_),
  };
  HelloRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      HelloRequest_descriptor_,
      HelloRequest::default_instance_,
      HelloRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HelloRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HelloRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(HelloRequest));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    HelloRequest_descriptor_, HelloRequest::default_instance_);
  HelloResponse_descriptor_ = file->message_type(4);
  HelloResponse::default_instance_ = new HelloResponse();
  static const int HelloResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HelloResponse, nid_),
  };
  HelloResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      HelloResponse_descriptor_,
      HelloResponse::default_instance_,
      HelloResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HelloResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HelloResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(HelloResponse));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    HelloResponse_descriptor_, HelloResponse::default_instance_);
  FindNodeRequest_descriptor_ = file->message_type(5);
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
  FindNodeResponse_descriptor_ = file->message_type(6);
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
  GetServicesResponse_Result_descriptor_ = GetServicesResponse_descriptor_->nested_type(0);
  GetServicesResponse_Result::default_instance_ = new GetServicesResponse_Result();
  static const int GetServicesResponse_Result_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetServicesResponse_Result, channel_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetServicesResponse_Result, name_),
  };
  GetServicesResponse_Result_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetServicesResponse_Result_descriptor_,
      GetServicesResponse_Result::default_instance_,
      GetServicesResponse_Result_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetServicesResponse_Result, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetServicesResponse_Result, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(GetServicesResponse_Result));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetServicesResponse_Result_descriptor_, GetServicesResponse_Result::default_instance_);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetServicesResponse_descriptor_, GetServicesResponse::default_instance_);
  GetChannelRequest_descriptor_ = file->message_type(9);
  GetChannelRequest::default_instance_ = new GetChannelRequest();
  static const int GetChannelRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetChannelRequest, name_),
  };
  GetChannelRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetChannelRequest_descriptor_,
      GetChannelRequest::default_instance_,
      GetChannelRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetChannelRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetChannelRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(GetChannelRequest));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetChannelRequest_descriptor_, GetChannelRequest::default_instance_);
  GetChannelResponse_descriptor_ = file->message_type(10);
  GetChannelResponse::default_instance_ = new GetChannelResponse();
  static const int GetChannelResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetChannelResponse, channel_),
  };
  GetChannelResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GetChannelResponse_descriptor_,
      GetChannelResponse::default_instance_,
      GetChannelResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetChannelResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GetChannelResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(GetChannelResponse));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GetChannelResponse_descriptor_, GetChannelResponse::default_instance_);
  AnnounceServiceRequest_descriptor_ = file->message_type(11);
  AnnounceServiceRequest::default_instance_ = new AnnounceServiceRequest();
  static const int AnnounceServiceRequest_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AnnounceServiceRequest, nid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AnnounceServiceRequest, service_),
  };
  AnnounceServiceRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AnnounceServiceRequest_descriptor_,
      AnnounceServiceRequest::default_instance_,
      AnnounceServiceRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AnnounceServiceRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AnnounceServiceRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(AnnounceServiceRequest));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AnnounceServiceRequest_descriptor_, AnnounceServiceRequest::default_instance_);
  AnnounceServiceResponse_descriptor_ = file->message_type(12);
  AnnounceServiceResponse::default_instance_ = new AnnounceServiceResponse();
  static const int AnnounceServiceResponse_offsets_[1] = {
  };
  AnnounceServiceResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AnnounceServiceResponse_descriptor_,
      AnnounceServiceResponse::default_instance_,
      AnnounceServiceResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AnnounceServiceResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AnnounceServiceResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      sizeof(AnnounceServiceResponse));
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AnnounceServiceResponse_descriptor_, AnnounceServiceResponse::default_instance_);
  Contact::default_instance_->InitAsDefaultInstance();
  PingRequest::default_instance_->InitAsDefaultInstance();
  PingResponse::default_instance_->InitAsDefaultInstance();
  HelloRequest::default_instance_->InitAsDefaultInstance();
  HelloResponse::default_instance_->InitAsDefaultInstance();
  FindNodeRequest::default_instance_->InitAsDefaultInstance();
  FindNodeResponse::default_instance_->InitAsDefaultInstance();
  GetServicesRequest::default_instance_->InitAsDefaultInstance();
  GetServicesResponse::default_instance_->InitAsDefaultInstance();
  GetServicesResponse_Result::default_instance_->InitAsDefaultInstance();
  GetChannelRequest::default_instance_->InitAsDefaultInstance();
  GetChannelResponse::default_instance_->InitAsDefaultInstance();
  AnnounceServiceRequest::default_instance_->InitAsDefaultInstance();
  AnnounceServiceResponse::default_instance_->InitAsDefaultInstance();
}

void protobuf_BuildDesc_core_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  ::google::protobuf::DescriptorPool* pool =
    ::google::protobuf::DescriptorPool::internal_generated_pool();

  pool->InternalBuildGeneratedFile(
    "\n\ncore.proto\022\017Sikozu.Messages\"@\n\007Contact"
    "\022\013\n\003nid\030\001 \002(\014\022\014\n\004ipv4\030\002 \001(\r\022\014\n\004ipv6\030\003 \001("
    "\014\022\014\n\004port\030\004 \002(\r\"\r\n\013PingRequest\"\016\n\014PingRe"
    "sponse\"\033\n\014HelloRequest\022\013\n\003nid\030\001 \001(\014\"\034\n\rH"
    "elloResponse\022\013\n\003nid\030\001 \001(\014\"/\n\017FindNodeReq"
    "uest\022\013\n\003nid\030\001 \002(\014\022\017\n\007service\030\002 \001(\t\">\n\020Fi"
    "ndNodeResponse\022*\n\010contacts\030\001 \003(\0132\030.Sikoz"
    "u.Messages.Contact\"\024\n\022GetServicesRequest"
    "\"}\n\023GetServicesResponse\022=\n\010services\030\001 \003("
    "\0132+.Sikozu.Messages.GetServicesResponse."
    "Result\032\'\n\006Result\022\017\n\007channel\030\001 \002(\r\022\014\n\004nam"
    "e\030\002 \002(\t\"!\n\021GetChannelRequest\022\014\n\004name\030\001 \002"
    "(\t\"%\n\022GetChannelResponse\022\017\n\007channel\030\001 \002("
    "\r\"6\n\026AnnounceServiceRequest\022\013\n\003nid\030\001 \002(\014"
    "\022\017\n\007service\030\002 \003(\t\"\031\n\027AnnounceServiceResp"
    "onse", 604,
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

const ::std::string HelloRequest::_default_nid_;
HelloRequest::HelloRequest()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    nid_(const_cast< ::std::string*>(&_default_nid_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void HelloRequest::InitAsDefaultInstance() {}

HelloRequest::HelloRequest(const HelloRequest& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    nid_(const_cast< ::std::string*>(&_default_nid_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

HelloRequest::~HelloRequest() {
  if (nid_ != &_default_nid_) {
    delete nid_;
  }
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* HelloRequest::descriptor() {
  if (HelloRequest_descriptor_ == NULL) protobuf_BuildDesc_core_2eproto();
  return HelloRequest_descriptor_;
}

const HelloRequest& HelloRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_core_2eproto();
  return *default_instance_;
}

HelloRequest* HelloRequest::default_instance_ = NULL;

HelloRequest* HelloRequest::New() const {
  return new HelloRequest;
}

const ::google::protobuf::Descriptor* HelloRequest::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* HelloRequest::GetReflection() const {
  if (HelloRequest_reflection_ == NULL) protobuf_BuildDesc_core_2eproto();
  return HelloRequest_reflection_;
}

// ===================================================================

const ::std::string HelloResponse::_default_nid_;
HelloResponse::HelloResponse()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    nid_(const_cast< ::std::string*>(&_default_nid_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void HelloResponse::InitAsDefaultInstance() {}

HelloResponse::HelloResponse(const HelloResponse& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    nid_(const_cast< ::std::string*>(&_default_nid_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

HelloResponse::~HelloResponse() {
  if (nid_ != &_default_nid_) {
    delete nid_;
  }
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* HelloResponse::descriptor() {
  if (HelloResponse_descriptor_ == NULL) protobuf_BuildDesc_core_2eproto();
  return HelloResponse_descriptor_;
}

const HelloResponse& HelloResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_core_2eproto();
  return *default_instance_;
}

HelloResponse* HelloResponse::default_instance_ = NULL;

HelloResponse* HelloResponse::New() const {
  return new HelloResponse;
}

const ::google::protobuf::Descriptor* HelloResponse::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* HelloResponse::GetReflection() const {
  if (HelloResponse_reflection_ == NULL) protobuf_BuildDesc_core_2eproto();
  return HelloResponse_reflection_;
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


const ::std::string GetServicesResponse_Result::_default_name_;
GetServicesResponse_Result::GetServicesResponse_Result()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    channel_(0u),
    name_(const_cast< ::std::string*>(&_default_name_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void GetServicesResponse_Result::InitAsDefaultInstance() {}

GetServicesResponse_Result::GetServicesResponse_Result(const GetServicesResponse_Result& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    channel_(0u),
    name_(const_cast< ::std::string*>(&_default_name_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

GetServicesResponse_Result::~GetServicesResponse_Result() {
  if (name_ != &_default_name_) {
    delete name_;
  }
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* GetServicesResponse_Result::descriptor() {
  if (GetServicesResponse_Result_descriptor_ == NULL) protobuf_BuildDesc_core_2eproto();
  return GetServicesResponse_Result_descriptor_;
}

const GetServicesResponse_Result& GetServicesResponse_Result::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_core_2eproto();
  return *default_instance_;
}

GetServicesResponse_Result* GetServicesResponse_Result::default_instance_ = NULL;

GetServicesResponse_Result* GetServicesResponse_Result::New() const {
  return new GetServicesResponse_Result;
}

const ::google::protobuf::Descriptor* GetServicesResponse_Result::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* GetServicesResponse_Result::GetReflection() const {
  if (GetServicesResponse_Result_reflection_ == NULL) protobuf_BuildDesc_core_2eproto();
  return GetServicesResponse_Result_reflection_;
}

// -------------------------------------------------------------------


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

const ::std::string GetChannelRequest::_default_name_;
GetChannelRequest::GetChannelRequest()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    name_(const_cast< ::std::string*>(&_default_name_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void GetChannelRequest::InitAsDefaultInstance() {}

GetChannelRequest::GetChannelRequest(const GetChannelRequest& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    name_(const_cast< ::std::string*>(&_default_name_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

GetChannelRequest::~GetChannelRequest() {
  if (name_ != &_default_name_) {
    delete name_;
  }
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* GetChannelRequest::descriptor() {
  if (GetChannelRequest_descriptor_ == NULL) protobuf_BuildDesc_core_2eproto();
  return GetChannelRequest_descriptor_;
}

const GetChannelRequest& GetChannelRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_core_2eproto();
  return *default_instance_;
}

GetChannelRequest* GetChannelRequest::default_instance_ = NULL;

GetChannelRequest* GetChannelRequest::New() const {
  return new GetChannelRequest;
}

const ::google::protobuf::Descriptor* GetChannelRequest::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* GetChannelRequest::GetReflection() const {
  if (GetChannelRequest_reflection_ == NULL) protobuf_BuildDesc_core_2eproto();
  return GetChannelRequest_reflection_;
}

// ===================================================================


GetChannelResponse::GetChannelResponse()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    channel_(0u) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void GetChannelResponse::InitAsDefaultInstance() {}

GetChannelResponse::GetChannelResponse(const GetChannelResponse& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    channel_(0u) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

GetChannelResponse::~GetChannelResponse() {
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* GetChannelResponse::descriptor() {
  if (GetChannelResponse_descriptor_ == NULL) protobuf_BuildDesc_core_2eproto();
  return GetChannelResponse_descriptor_;
}

const GetChannelResponse& GetChannelResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_core_2eproto();
  return *default_instance_;
}

GetChannelResponse* GetChannelResponse::default_instance_ = NULL;

GetChannelResponse* GetChannelResponse::New() const {
  return new GetChannelResponse;
}

const ::google::protobuf::Descriptor* GetChannelResponse::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* GetChannelResponse::GetReflection() const {
  if (GetChannelResponse_reflection_ == NULL) protobuf_BuildDesc_core_2eproto();
  return GetChannelResponse_reflection_;
}

// ===================================================================

const ::std::string AnnounceServiceRequest::_default_nid_;

AnnounceServiceRequest::AnnounceServiceRequest()
  : ::google::protobuf::Message(),
    _cached_size_(0),
    nid_(const_cast< ::std::string*>(&_default_nid_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void AnnounceServiceRequest::InitAsDefaultInstance() {}

AnnounceServiceRequest::AnnounceServiceRequest(const AnnounceServiceRequest& from)
  : ::google::protobuf::Message(),
    _cached_size_(0),
    nid_(const_cast< ::std::string*>(&_default_nid_)) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

AnnounceServiceRequest::~AnnounceServiceRequest() {
  if (nid_ != &_default_nid_) {
    delete nid_;
  }
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* AnnounceServiceRequest::descriptor() {
  if (AnnounceServiceRequest_descriptor_ == NULL) protobuf_BuildDesc_core_2eproto();
  return AnnounceServiceRequest_descriptor_;
}

const AnnounceServiceRequest& AnnounceServiceRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_core_2eproto();
  return *default_instance_;
}

AnnounceServiceRequest* AnnounceServiceRequest::default_instance_ = NULL;

AnnounceServiceRequest* AnnounceServiceRequest::New() const {
  return new AnnounceServiceRequest;
}

const ::google::protobuf::Descriptor* AnnounceServiceRequest::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* AnnounceServiceRequest::GetReflection() const {
  if (AnnounceServiceRequest_reflection_ == NULL) protobuf_BuildDesc_core_2eproto();
  return AnnounceServiceRequest_reflection_;
}

// ===================================================================

AnnounceServiceResponse::AnnounceServiceResponse()
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

void AnnounceServiceResponse::InitAsDefaultInstance() {}

AnnounceServiceResponse::AnnounceServiceResponse(const AnnounceServiceResponse& from)
  : ::google::protobuf::Message(),
    _cached_size_(0) {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  MergeFrom(from);
}

AnnounceServiceResponse::~AnnounceServiceResponse() {
  if (this != default_instance_) {
  }
}

const ::google::protobuf::Descriptor* AnnounceServiceResponse::descriptor() {
  if (AnnounceServiceResponse_descriptor_ == NULL) protobuf_BuildDesc_core_2eproto();
  return AnnounceServiceResponse_descriptor_;
}

const AnnounceServiceResponse& AnnounceServiceResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_BuildDesc_core_2eproto();
  return *default_instance_;
}

AnnounceServiceResponse* AnnounceServiceResponse::default_instance_ = NULL;

AnnounceServiceResponse* AnnounceServiceResponse::New() const {
  return new AnnounceServiceResponse;
}

const ::google::protobuf::Descriptor* AnnounceServiceResponse::GetDescriptor() const {
  return descriptor();
}

const ::google::protobuf::Reflection* AnnounceServiceResponse::GetReflection() const {
  if (AnnounceServiceResponse_reflection_ == NULL) protobuf_BuildDesc_core_2eproto();
  return AnnounceServiceResponse_reflection_;
}

}  // namespace Messages
}  // namespace Sikozu
