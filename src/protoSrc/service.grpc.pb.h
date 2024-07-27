// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: service.proto
#ifndef GRPC_service_2eproto__INCLUDED
#define GRPC_service_2eproto__INCLUDED

#include "service.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>

namespace service {

class Dservice final {
 public:
  static constexpr char const* service_full_name() {
    return "service.Dservice";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // Upload file from Client side to the Server side
    std::unique_ptr< ::grpc::ClientWriterInterface< ::service::FileChunk>> upload(::grpc::ClientContext* context, ::service::Response* response) {
      return std::unique_ptr< ::grpc::ClientWriterInterface< ::service::FileChunk>>(uploadRaw(context, response));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::service::FileChunk>> Asyncupload(::grpc::ClientContext* context, ::service::Response* response, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::service::FileChunk>>(AsyncuploadRaw(context, response, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::service::FileChunk>> PrepareAsyncupload(::grpc::ClientContext* context, ::service::Response* response, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::service::FileChunk>>(PrepareAsyncuploadRaw(context, response, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      // Upload file from Client side to the Server side
      virtual void upload(::grpc::ClientContext* context, ::service::Response* response, ::grpc::ClientWriteReactor< ::service::FileChunk>* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientWriterInterface< ::service::FileChunk>* uploadRaw(::grpc::ClientContext* context, ::service::Response* response) = 0;
    virtual ::grpc::ClientAsyncWriterInterface< ::service::FileChunk>* AsyncuploadRaw(::grpc::ClientContext* context, ::service::Response* response, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncWriterInterface< ::service::FileChunk>* PrepareAsyncuploadRaw(::grpc::ClientContext* context, ::service::Response* response, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    std::unique_ptr< ::grpc::ClientWriter< ::service::FileChunk>> upload(::grpc::ClientContext* context, ::service::Response* response) {
      return std::unique_ptr< ::grpc::ClientWriter< ::service::FileChunk>>(uploadRaw(context, response));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriter< ::service::FileChunk>> Asyncupload(::grpc::ClientContext* context, ::service::Response* response, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncWriter< ::service::FileChunk>>(AsyncuploadRaw(context, response, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriter< ::service::FileChunk>> PrepareAsyncupload(::grpc::ClientContext* context, ::service::Response* response, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncWriter< ::service::FileChunk>>(PrepareAsyncuploadRaw(context, response, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void upload(::grpc::ClientContext* context, ::service::Response* response, ::grpc::ClientWriteReactor< ::service::FileChunk>* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientWriter< ::service::FileChunk>* uploadRaw(::grpc::ClientContext* context, ::service::Response* response) override;
    ::grpc::ClientAsyncWriter< ::service::FileChunk>* AsyncuploadRaw(::grpc::ClientContext* context, ::service::Response* response, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncWriter< ::service::FileChunk>* PrepareAsyncuploadRaw(::grpc::ClientContext* context, ::service::Response* response, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_upload_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // Upload file from Client side to the Server side
    virtual ::grpc::Status upload(::grpc::ServerContext* context, ::grpc::ServerReader< ::service::FileChunk>* reader, ::service::Response* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_upload : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_upload() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_upload() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status upload(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::service::FileChunk>* /*reader*/, ::service::Response* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestupload(::grpc::ServerContext* context, ::grpc::ServerAsyncReader< ::service::Response, ::service::FileChunk>* reader, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncClientStreaming(0, context, reader, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_upload<Service > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_upload : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_upload() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackClientStreamingHandler< ::service::FileChunk, ::service::Response>(
            [this](
                   ::grpc::CallbackServerContext* context, ::service::Response* response) { return this->upload(context, response); }));
    }
    ~WithCallbackMethod_upload() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status upload(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::service::FileChunk>* /*reader*/, ::service::Response* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerReadReactor< ::service::FileChunk>* upload(
      ::grpc::CallbackServerContext* /*context*/, ::service::Response* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_upload<Service > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_upload : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_upload() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_upload() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status upload(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::service::FileChunk>* /*reader*/, ::service::Response* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_upload : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_upload() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_upload() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status upload(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::service::FileChunk>* /*reader*/, ::service::Response* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void Requestupload(::grpc::ServerContext* context, ::grpc::ServerAsyncReader< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* reader, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncClientStreaming(0, context, reader, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_upload : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_upload() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackClientStreamingHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, ::grpc::ByteBuffer* response) { return this->upload(context, response); }));
    }
    ~WithRawCallbackMethod_upload() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status upload(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::service::FileChunk>* /*reader*/, ::service::Response* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerReadReactor< ::grpc::ByteBuffer>* upload(
      ::grpc::CallbackServerContext* /*context*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  typedef Service StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef Service StreamedService;
};

}  // namespace service


#endif  // GRPC_service_2eproto__INCLUDED
