// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: common.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "common.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Common {

namespace {

const ::google::protobuf::Descriptor* HeadFlag_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HeadFlag_reflection_ = NULL;
const ::google::protobuf::Descriptor* Head_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Head_reflection_ = NULL;
const ::google::protobuf::Descriptor* CommonMsg_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CommonMsg_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_common_2eproto() {
  protobuf_AddDesc_common_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "common.proto");
  GOOGLE_CHECK(file != NULL);
  HeadFlag_descriptor_ = file->message_type(0);
  static const int HeadFlag_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeadFlag, magic_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeadFlag, headcrc_),
  };
  HeadFlag_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      HeadFlag_descriptor_,
      HeadFlag::default_instance_,
      HeadFlag_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeadFlag, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeadFlag, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(HeadFlag));
  Head_descriptor_ = file->message_type(1);
  static const int Head_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Head, bodytype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Head, bodysize_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Head, bodycrc_),
  };
  Head_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Head_descriptor_,
      Head::default_instance_,
      Head_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Head, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Head, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Head));
  CommonMsg_descriptor_ = file->message_type(2);
  static const int CommonMsg_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CommonMsg, err_),
  };
  CommonMsg_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CommonMsg_descriptor_,
      CommonMsg::default_instance_,
      CommonMsg_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CommonMsg, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CommonMsg, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CommonMsg));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_common_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    HeadFlag_descriptor_, &HeadFlag::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Head_descriptor_, &Head::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CommonMsg_descriptor_, &CommonMsg::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_common_2eproto() {
  delete HeadFlag::default_instance_;
  delete HeadFlag_reflection_;
  delete Head::default_instance_;
  delete Head_reflection_;
  delete CommonMsg::default_instance_;
  delete CommonMsg_reflection_;
}

void protobuf_AddDesc_common_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\014common.proto\022\006Common\"*\n\010HeadFlag\022\r\n\005ma"
    "gic\030\001 \002(\007\022\017\n\007headcrc\030\002 \002(\007\";\n\004Head\022\020\n\010bo"
    "dytype\030\001 \002(\007\022\020\n\010bodysize\030\002 \002(\007\022\017\n\007bodycr"
    "c\030\003 \002(\007\"\030\n\tCommonMsg\022\013\n\003err\030\001 \002(\005", 153);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "common.proto", &protobuf_RegisterTypes);
  HeadFlag::default_instance_ = new HeadFlag();
  Head::default_instance_ = new Head();
  CommonMsg::default_instance_ = new CommonMsg();
  HeadFlag::default_instance_->InitAsDefaultInstance();
  Head::default_instance_->InitAsDefaultInstance();
  CommonMsg::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_common_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_common_2eproto {
  StaticDescriptorInitializer_common_2eproto() {
    protobuf_AddDesc_common_2eproto();
  }
} static_descriptor_initializer_common_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int HeadFlag::kMagicFieldNumber;
const int HeadFlag::kHeadcrcFieldNumber;
#endif  // !_MSC_VER

HeadFlag::HeadFlag()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void HeadFlag::InitAsDefaultInstance() {
}

HeadFlag::HeadFlag(const HeadFlag& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void HeadFlag::SharedCtor() {
  _cached_size_ = 0;
  magic_ = 0u;
  headcrc_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HeadFlag::~HeadFlag() {
  SharedDtor();
}

void HeadFlag::SharedDtor() {
  if (this != default_instance_) {
  }
}

void HeadFlag::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* HeadFlag::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return HeadFlag_descriptor_;
}

const HeadFlag& HeadFlag::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_common_2eproto();
  return *default_instance_;
}

HeadFlag* HeadFlag::default_instance_ = NULL;

HeadFlag* HeadFlag::New() const {
  return new HeadFlag;
}

void HeadFlag::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    magic_ = 0u;
    headcrc_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool HeadFlag::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required fixed32 magic = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &magic_)));
          set_has_magic();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(21)) goto parse_headcrc;
        break;
      }

      // required fixed32 headcrc = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
         parse_headcrc:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &headcrc_)));
          set_has_headcrc();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void HeadFlag::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required fixed32 magic = 1;
  if (has_magic()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->magic(), output);
  }

  // required fixed32 headcrc = 2;
  if (has_headcrc()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->headcrc(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* HeadFlag::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required fixed32 magic = 1;
  if (has_magic()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->magic(), target);
  }

  // required fixed32 headcrc = 2;
  if (has_headcrc()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->headcrc(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int HeadFlag::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required fixed32 magic = 1;
    if (has_magic()) {
      total_size += 1 + 4;
    }

    // required fixed32 headcrc = 2;
    if (has_headcrc()) {
      total_size += 1 + 4;
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void HeadFlag::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const HeadFlag* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const HeadFlag*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void HeadFlag::MergeFrom(const HeadFlag& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_magic()) {
      set_magic(from.magic());
    }
    if (from.has_headcrc()) {
      set_headcrc(from.headcrc());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void HeadFlag::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HeadFlag::CopyFrom(const HeadFlag& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HeadFlag::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void HeadFlag::Swap(HeadFlag* other) {
  if (other != this) {
    std::swap(magic_, other->magic_);
    std::swap(headcrc_, other->headcrc_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata HeadFlag::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = HeadFlag_descriptor_;
  metadata.reflection = HeadFlag_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int Head::kBodytypeFieldNumber;
const int Head::kBodysizeFieldNumber;
const int Head::kBodycrcFieldNumber;
#endif  // !_MSC_VER

Head::Head()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Head::InitAsDefaultInstance() {
}

Head::Head(const Head& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Head::SharedCtor() {
  _cached_size_ = 0;
  bodytype_ = 0u;
  bodysize_ = 0u;
  bodycrc_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Head::~Head() {
  SharedDtor();
}

void Head::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Head::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Head::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Head_descriptor_;
}

const Head& Head::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_common_2eproto();
  return *default_instance_;
}

Head* Head::default_instance_ = NULL;

Head* Head::New() const {
  return new Head;
}

void Head::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    bodytype_ = 0u;
    bodysize_ = 0u;
    bodycrc_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Head::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required fixed32 bodytype = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &bodytype_)));
          set_has_bodytype();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(21)) goto parse_bodysize;
        break;
      }

      // required fixed32 bodysize = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
         parse_bodysize:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &bodysize_)));
          set_has_bodysize();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(29)) goto parse_bodycrc;
        break;
      }

      // required fixed32 bodycrc = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
         parse_bodycrc:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &bodycrc_)));
          set_has_bodycrc();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Head::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required fixed32 bodytype = 1;
  if (has_bodytype()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->bodytype(), output);
  }

  // required fixed32 bodysize = 2;
  if (has_bodysize()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->bodysize(), output);
  }

  // required fixed32 bodycrc = 3;
  if (has_bodycrc()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(3, this->bodycrc(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Head::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required fixed32 bodytype = 1;
  if (has_bodytype()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->bodytype(), target);
  }

  // required fixed32 bodysize = 2;
  if (has_bodysize()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->bodysize(), target);
  }

  // required fixed32 bodycrc = 3;
  if (has_bodycrc()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(3, this->bodycrc(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Head::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required fixed32 bodytype = 1;
    if (has_bodytype()) {
      total_size += 1 + 4;
    }

    // required fixed32 bodysize = 2;
    if (has_bodysize()) {
      total_size += 1 + 4;
    }

    // required fixed32 bodycrc = 3;
    if (has_bodycrc()) {
      total_size += 1 + 4;
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Head::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Head* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Head*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Head::MergeFrom(const Head& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_bodytype()) {
      set_bodytype(from.bodytype());
    }
    if (from.has_bodysize()) {
      set_bodysize(from.bodysize());
    }
    if (from.has_bodycrc()) {
      set_bodycrc(from.bodycrc());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Head::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Head::CopyFrom(const Head& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Head::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;

  return true;
}

void Head::Swap(Head* other) {
  if (other != this) {
    std::swap(bodytype_, other->bodytype_);
    std::swap(bodysize_, other->bodysize_);
    std::swap(bodycrc_, other->bodycrc_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Head::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Head_descriptor_;
  metadata.reflection = Head_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int CommonMsg::kErrFieldNumber;
#endif  // !_MSC_VER

CommonMsg::CommonMsg()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void CommonMsg::InitAsDefaultInstance() {
}

CommonMsg::CommonMsg(const CommonMsg& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void CommonMsg::SharedCtor() {
  _cached_size_ = 0;
  err_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CommonMsg::~CommonMsg() {
  SharedDtor();
}

void CommonMsg::SharedDtor() {
  if (this != default_instance_) {
  }
}

void CommonMsg::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CommonMsg::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CommonMsg_descriptor_;
}

const CommonMsg& CommonMsg::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_common_2eproto();
  return *default_instance_;
}

CommonMsg* CommonMsg::default_instance_ = NULL;

CommonMsg* CommonMsg::New() const {
  return new CommonMsg;
}

void CommonMsg::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    err_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CommonMsg::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 err = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &err_)));
          set_has_err();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void CommonMsg::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 err = 1;
  if (has_err()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->err(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* CommonMsg::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 err = 1;
  if (has_err()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->err(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int CommonMsg::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 err = 1;
    if (has_err()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->err());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CommonMsg::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CommonMsg* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CommonMsg*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CommonMsg::MergeFrom(const CommonMsg& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_err()) {
      set_err(from.err());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CommonMsg::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CommonMsg::CopyFrom(const CommonMsg& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CommonMsg::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void CommonMsg::Swap(CommonMsg* other) {
  if (other != this) {
    std::swap(err_, other->err_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CommonMsg::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CommonMsg_descriptor_;
  metadata.reflection = CommonMsg_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Common

// @@protoc_insertion_point(global_scope)
