// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: greeter.proto
// Protobuf C++ Version: 5.27.1

#ifndef GOOGLE_PROTOBUF_INCLUDED_greeter_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_greeter_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/runtime_version.h"
#if PROTOBUF_VERSION != 5027001
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_greeter_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_greeter_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_greeter_2eproto;
namespace greeter {
class HelloReply;
struct HelloReplyDefaultTypeInternal;
extern HelloReplyDefaultTypeInternal _HelloReply_default_instance_;
class HelloRequest;
struct HelloRequestDefaultTypeInternal;
extern HelloRequestDefaultTypeInternal _HelloRequest_default_instance_;
}  // namespace greeter
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace greeter {

// ===================================================================


// -------------------------------------------------------------------

class HelloRequest final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:greeter.HelloRequest) */ {
 public:
  inline HelloRequest() : HelloRequest(nullptr) {}
  ~HelloRequest() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR HelloRequest(
      ::google::protobuf::internal::ConstantInitialized);

  inline HelloRequest(const HelloRequest& from) : HelloRequest(nullptr, from) {}
  inline HelloRequest(HelloRequest&& from) noexcept
      : HelloRequest(nullptr, std::move(from)) {}
  inline HelloRequest& operator=(const HelloRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline HelloRequest& operator=(HelloRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const HelloRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const HelloRequest* internal_default_instance() {
    return reinterpret_cast<const HelloRequest*>(
        &_HelloRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(HelloRequest& a, HelloRequest& b) { a.Swap(&b); }
  inline void Swap(HelloRequest* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(HelloRequest* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  HelloRequest* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<HelloRequest>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const HelloRequest& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const HelloRequest& from) { HelloRequest::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(HelloRequest* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "greeter.HelloRequest"; }

 protected:
  explicit HelloRequest(::google::protobuf::Arena* arena);
  HelloRequest(::google::protobuf::Arena* arena, const HelloRequest& from);
  HelloRequest(::google::protobuf::Arena* arena, HelloRequest&& from) noexcept
      : HelloRequest(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::Message::ClassData* GetClassData() const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kNameFieldNumber = 1,
  };
  // string name = 1;
  void clear_name() ;
  const std::string& name() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_name(Arg_&& arg, Args_... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* value);

  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(
      const std::string& value);
  std::string* _internal_mutable_name();

  public:
  // @@protoc_insertion_point(class_scope:greeter.HelloRequest)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      33, 2>
      _table_;

  static constexpr const void* _raw_default_instance_ =
      &_HelloRequest_default_instance_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const HelloRequest& from_msg);
    ::google::protobuf::internal::ArenaStringPtr name_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_greeter_2eproto;
};
// -------------------------------------------------------------------

class HelloReply final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:greeter.HelloReply) */ {
 public:
  inline HelloReply() : HelloReply(nullptr) {}
  ~HelloReply() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR HelloReply(
      ::google::protobuf::internal::ConstantInitialized);

  inline HelloReply(const HelloReply& from) : HelloReply(nullptr, from) {}
  inline HelloReply(HelloReply&& from) noexcept
      : HelloReply(nullptr, std::move(from)) {}
  inline HelloReply& operator=(const HelloReply& from) {
    CopyFrom(from);
    return *this;
  }
  inline HelloReply& operator=(HelloReply&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const HelloReply& default_instance() {
    return *internal_default_instance();
  }
  static inline const HelloReply* internal_default_instance() {
    return reinterpret_cast<const HelloReply*>(
        &_HelloReply_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 1;
  friend void swap(HelloReply& a, HelloReply& b) { a.Swap(&b); }
  inline void Swap(HelloReply* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(HelloReply* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  HelloReply* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<HelloReply>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const HelloReply& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const HelloReply& from) { HelloReply::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(HelloReply* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "greeter.HelloReply"; }

 protected:
  explicit HelloReply(::google::protobuf::Arena* arena);
  HelloReply(::google::protobuf::Arena* arena, const HelloReply& from);
  HelloReply(::google::protobuf::Arena* arena, HelloReply&& from) noexcept
      : HelloReply(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::Message::ClassData* GetClassData() const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kMessageFieldNumber = 1,
  };
  // string message = 1;
  void clear_message() ;
  const std::string& message() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_message(Arg_&& arg, Args_... args);
  std::string* mutable_message();
  PROTOBUF_NODISCARD std::string* release_message();
  void set_allocated_message(std::string* value);

  private:
  const std::string& _internal_message() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_message(
      const std::string& value);
  std::string* _internal_mutable_message();

  public:
  // @@protoc_insertion_point(class_scope:greeter.HelloReply)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      34, 2>
      _table_;

  static constexpr const void* _raw_default_instance_ =
      &_HelloReply_default_instance_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const HelloReply& from_msg);
    ::google::protobuf::internal::ArenaStringPtr message_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_greeter_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// HelloRequest

// string name = 1;
inline void HelloRequest::clear_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.ClearToEmpty();
}
inline const std::string& HelloRequest::name() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:greeter.HelloRequest.name)
  return _internal_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void HelloRequest::set_name(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:greeter.HelloRequest.name)
}
inline std::string* HelloRequest::mutable_name() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:greeter.HelloRequest.name)
  return _s;
}
inline const std::string& HelloRequest::_internal_name() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.name_.Get();
}
inline void HelloRequest::_internal_set_name(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.Set(value, GetArena());
}
inline std::string* HelloRequest::_internal_mutable_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.name_.Mutable( GetArena());
}
inline std::string* HelloRequest::release_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:greeter.HelloRequest.name)
  return _impl_.name_.Release();
}
inline void HelloRequest::set_allocated_name(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.name_.IsDefault()) {
          _impl_.name_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:greeter.HelloRequest.name)
}

// -------------------------------------------------------------------

// HelloReply

// string message = 1;
inline void HelloReply::clear_message() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.message_.ClearToEmpty();
}
inline const std::string& HelloReply::message() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:greeter.HelloReply.message)
  return _internal_message();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void HelloReply::set_message(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.message_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:greeter.HelloReply.message)
}
inline std::string* HelloReply::mutable_message() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_message();
  // @@protoc_insertion_point(field_mutable:greeter.HelloReply.message)
  return _s;
}
inline const std::string& HelloReply::_internal_message() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.message_.Get();
}
inline void HelloReply::_internal_set_message(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.message_.Set(value, GetArena());
}
inline std::string* HelloReply::_internal_mutable_message() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.message_.Mutable( GetArena());
}
inline std::string* HelloReply::release_message() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:greeter.HelloReply.message)
  return _impl_.message_.Release();
}
inline void HelloReply::set_allocated_message(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.message_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.message_.IsDefault()) {
          _impl_.message_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:greeter.HelloReply.message)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace greeter


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_greeter_2eproto_2epb_2eh
