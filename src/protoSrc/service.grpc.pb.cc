// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: service.proto

#include "service.pb.h"
#include "service.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace service {

static const char* Dservice_method_names[] = {
  "/service.Dservice/upload",
  "/service.Dservice/download",
  "/service.Dservice/list",
  "/service.Dservice/deleteFile",
};

std::unique_ptr< Dservice::Stub> Dservice::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Dservice::Stub> stub(new Dservice::Stub(channel, options));
  return stub;
}

Dservice::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_upload_(Dservice_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::CLIENT_STREAMING, channel)
  , rpcmethod_download_(Dservice_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_list_(Dservice_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_deleteFile_(Dservice_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::ClientWriter< ::service::FileChunk>* Dservice::Stub::uploadRaw(::grpc::ClientContext* context, ::service::Response* response) {
  return ::grpc::internal::ClientWriterFactory< ::service::FileChunk>::Create(channel_.get(), rpcmethod_upload_, context, response);
}

void Dservice::Stub::async::upload(::grpc::ClientContext* context, ::service::Response* response, ::grpc::ClientWriteReactor< ::service::FileChunk>* reactor) {
  ::grpc::internal::ClientCallbackWriterFactory< ::service::FileChunk>::Create(stub_->channel_.get(), stub_->rpcmethod_upload_, context, response, reactor);
}

::grpc::ClientAsyncWriter< ::service::FileChunk>* Dservice::Stub::AsyncuploadRaw(::grpc::ClientContext* context, ::service::Response* response, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::service::FileChunk>::Create(channel_.get(), cq, rpcmethod_upload_, context, response, true, tag);
}

::grpc::ClientAsyncWriter< ::service::FileChunk>* Dservice::Stub::PrepareAsyncuploadRaw(::grpc::ClientContext* context, ::service::Response* response, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncWriterFactory< ::service::FileChunk>::Create(channel_.get(), cq, rpcmethod_upload_, context, response, false, nullptr);
}

::grpc::ClientReader< ::service::FileChunk>* Dservice::Stub::downloadRaw(::grpc::ClientContext* context, const ::service::Request& request) {
  return ::grpc::internal::ClientReaderFactory< ::service::FileChunk>::Create(channel_.get(), rpcmethod_download_, context, request);
}

void Dservice::Stub::async::download(::grpc::ClientContext* context, const ::service::Request* request, ::grpc::ClientReadReactor< ::service::FileChunk>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::service::FileChunk>::Create(stub_->channel_.get(), stub_->rpcmethod_download_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::service::FileChunk>* Dservice::Stub::AsyncdownloadRaw(::grpc::ClientContext* context, const ::service::Request& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::service::FileChunk>::Create(channel_.get(), cq, rpcmethod_download_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::service::FileChunk>* Dservice::Stub::PrepareAsyncdownloadRaw(::grpc::ClientContext* context, const ::service::Request& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::service::FileChunk>::Create(channel_.get(), cq, rpcmethod_download_, context, request, false, nullptr);
}

::grpc::Status Dservice::Stub::list(::grpc::ClientContext* context, const ::service::Empty& request, ::service::Files* response) {
  return ::grpc::internal::BlockingUnaryCall< ::service::Empty, ::service::Files, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_list_, context, request, response);
}

void Dservice::Stub::async::list(::grpc::ClientContext* context, const ::service::Empty* request, ::service::Files* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::service::Empty, ::service::Files, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_list_, context, request, response, std::move(f));
}

void Dservice::Stub::async::list(::grpc::ClientContext* context, const ::service::Empty* request, ::service::Files* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_list_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::service::Files>* Dservice::Stub::PrepareAsynclistRaw(::grpc::ClientContext* context, const ::service::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::service::Files, ::service::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_list_, context, request);
}

::grpc::ClientAsyncResponseReader< ::service::Files>* Dservice::Stub::AsynclistRaw(::grpc::ClientContext* context, const ::service::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsynclistRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status Dservice::Stub::deleteFile(::grpc::ClientContext* context, const ::service::Request& request, ::service::Response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::service::Request, ::service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_deleteFile_, context, request, response);
}

void Dservice::Stub::async::deleteFile(::grpc::ClientContext* context, const ::service::Request* request, ::service::Response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::service::Request, ::service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_deleteFile_, context, request, response, std::move(f));
}

void Dservice::Stub::async::deleteFile(::grpc::ClientContext* context, const ::service::Request* request, ::service::Response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_deleteFile_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::service::Response>* Dservice::Stub::PrepareAsyncdeleteFileRaw(::grpc::ClientContext* context, const ::service::Request& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::service::Response, ::service::Request, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_deleteFile_, context, request);
}

::grpc::ClientAsyncResponseReader< ::service::Response>* Dservice::Stub::AsyncdeleteFileRaw(::grpc::ClientContext* context, const ::service::Request& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncdeleteFileRaw(context, request, cq);
  result->StartCall();
  return result;
}

Dservice::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Dservice_method_names[0],
      ::grpc::internal::RpcMethod::CLIENT_STREAMING,
      new ::grpc::internal::ClientStreamingHandler< Dservice::Service, ::service::FileChunk, ::service::Response>(
          [](Dservice::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReader<::service::FileChunk>* reader,
             ::service::Response* resp) {
               return service->upload(ctx, reader, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Dservice_method_names[1],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< Dservice::Service, ::service::Request, ::service::FileChunk>(
          [](Dservice::Service* service,
             ::grpc::ServerContext* ctx,
             const ::service::Request* req,
             ::grpc::ServerWriter<::service::FileChunk>* writer) {
               return service->download(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Dservice_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Dservice::Service, ::service::Empty, ::service::Files, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Dservice::Service* service,
             ::grpc::ServerContext* ctx,
             const ::service::Empty* req,
             ::service::Files* resp) {
               return service->list(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Dservice_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Dservice::Service, ::service::Request, ::service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Dservice::Service* service,
             ::grpc::ServerContext* ctx,
             const ::service::Request* req,
             ::service::Response* resp) {
               return service->deleteFile(ctx, req, resp);
             }, this)));
}

Dservice::Service::~Service() {
}

::grpc::Status Dservice::Service::upload(::grpc::ServerContext* context, ::grpc::ServerReader< ::service::FileChunk>* reader, ::service::Response* response) {
  (void) context;
  (void) reader;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Dservice::Service::download(::grpc::ServerContext* context, const ::service::Request* request, ::grpc::ServerWriter< ::service::FileChunk>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Dservice::Service::list(::grpc::ServerContext* context, const ::service::Empty* request, ::service::Files* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Dservice::Service::deleteFile(::grpc::ServerContext* context, const ::service::Request* request, ::service::Response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace service

