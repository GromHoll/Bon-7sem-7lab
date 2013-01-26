// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessagePacket.proto

#ifndef PROTOBUF_MessagePacket_2eproto__INCLUDED
#define PROTOBUF_MessagePacket_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

namespace proto {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_MessagePacket_2eproto();
void protobuf_AssignDesc_MessagePacket_2eproto();
void protobuf_ShutdownFile_MessagePacket_2eproto();

class Message;

// ===================================================================

class Message : public ::google::protobuf::Message {
 public:
  Message();
  virtual ~Message();
  
  Message(const Message& from);
  
  inline Message& operator=(const Message& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Message& default_instance();
  
  void Swap(Message* other);
  
  // implements Message ----------------------------------------------
  
  Message* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Message& from);
  void MergeFrom(const Message& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required string command = 1;
  inline bool has_command() const;
  inline void clear_command();
  static const int kCommandFieldNumber = 1;
  inline const ::std::string& command() const;
  inline void set_command(const ::std::string& value);
  inline void set_command(const char* value);
  inline void set_command(const char* value, size_t size);
  inline ::std::string* mutable_command();
  inline ::std::string* release_command();
  
  // optional string argument = 2;
  inline bool has_argument() const;
  inline void clear_argument();
  static const int kArgumentFieldNumber = 2;
  inline const ::std::string& argument() const;
  inline void set_argument(const ::std::string& value);
  inline void set_argument(const char* value);
  inline void set_argument(const char* value, size_t size);
  inline ::std::string* mutable_argument();
  inline ::std::string* release_argument();
  
  // @@protoc_insertion_point(class_scope:proto.Message)
 private:
  inline void set_has_command();
  inline void clear_has_command();
  inline void set_has_argument();
  inline void clear_has_argument();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* command_;
  ::std::string* argument_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];
  
  friend void  protobuf_AddDesc_MessagePacket_2eproto();
  friend void protobuf_AssignDesc_MessagePacket_2eproto();
  friend void protobuf_ShutdownFile_MessagePacket_2eproto();
  
  void InitAsDefaultInstance();
  static Message* default_instance_;
};
// ===================================================================


// ===================================================================

// Message

// required string command = 1;
inline bool Message::has_command() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Message::set_has_command() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Message::clear_has_command() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Message::clear_command() {
  if (command_ != &::google::protobuf::internal::kEmptyString) {
    command_->clear();
  }
  clear_has_command();
}
inline const ::std::string& Message::command() const {
  return *command_;
}
inline void Message::set_command(const ::std::string& value) {
  set_has_command();
  if (command_ == &::google::protobuf::internal::kEmptyString) {
    command_ = new ::std::string;
  }
  command_->assign(value);
}
inline void Message::set_command(const char* value) {
  set_has_command();
  if (command_ == &::google::protobuf::internal::kEmptyString) {
    command_ = new ::std::string;
  }
  command_->assign(value);
}
inline void Message::set_command(const char* value, size_t size) {
  set_has_command();
  if (command_ == &::google::protobuf::internal::kEmptyString) {
    command_ = new ::std::string;
  }
  command_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Message::mutable_command() {
  set_has_command();
  if (command_ == &::google::protobuf::internal::kEmptyString) {
    command_ = new ::std::string;
  }
  return command_;
}
inline ::std::string* Message::release_command() {
  clear_has_command();
  if (command_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = command_;
    command_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional string argument = 2;
inline bool Message::has_argument() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Message::set_has_argument() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Message::clear_has_argument() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Message::clear_argument() {
  if (argument_ != &::google::protobuf::internal::kEmptyString) {
    argument_->clear();
  }
  clear_has_argument();
}
inline const ::std::string& Message::argument() const {
  return *argument_;
}
inline void Message::set_argument(const ::std::string& value) {
  set_has_argument();
  if (argument_ == &::google::protobuf::internal::kEmptyString) {
    argument_ = new ::std::string;
  }
  argument_->assign(value);
}
inline void Message::set_argument(const char* value) {
  set_has_argument();
  if (argument_ == &::google::protobuf::internal::kEmptyString) {
    argument_ = new ::std::string;
  }
  argument_->assign(value);
}
inline void Message::set_argument(const char* value, size_t size) {
  set_has_argument();
  if (argument_ == &::google::protobuf::internal::kEmptyString) {
    argument_ = new ::std::string;
  }
  argument_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Message::mutable_argument() {
  set_has_argument();
  if (argument_ == &::google::protobuf::internal::kEmptyString) {
    argument_ = new ::std::string;
  }
  return argument_;
}
inline ::std::string* Message::release_argument() {
  clear_has_argument();
  if (argument_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = argument_;
    argument_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MessagePacket_2eproto__INCLUDED