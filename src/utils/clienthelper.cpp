#include "clienthelper.h"
#include "../protoSrc/service.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <fstream>

using namespace std;
using service::FileChunk;
using service::Response;
using grpc::ClientContext;
using grpc::Status;

//*.grpc.pb.h and *.grpc.pb.cc contain the classes and methods for gRPC services defined in the .proto file

ClientHelper::ClientHelper(const shared_ptr<Channel> channel): stub_(service::Dservice::NewStub(channel)){}

ClientHelper::~ClientHelper(){}

void ClientHelper::setPath(string path){
    this->path_ = path;
}


string ClientHelper::upload(const string & filename){

    FileChunk filechunk;
    Response response;
    ClientContext context;
    //1. pass the filename to server

    context.AddMetadata("namekey", filename);
    response.set_message(filename);

    //::grpc::Status upload(::grpc::ClientContext* context, const ::service::FileChunk& request, ::service::Response* response) override;
    //stream: std::unique_ptr< ::grpc::ClientWriter< ::service::FileChunk>> upload(::grpc::ClientContext* context, ::service::Response* response)
    unique_ptr< ::grpc::ClientWriter< ::service::FileChunk>> resp = stub_->upload(&context, &response);
    string filenm = this->path_ + filename;
    fstream file = fstream(filenm, ios::in|ios::binary);
    if(!file){
        cerr<<"File could not be opened"<<endl;
        return "Failed";
    }else{
        cout << "File "<<filenm<<" open successfuly" << endl;
        // Get the file size

        int size = std::filesystem::file_size(filenm);
        std::cout << "Size of the data: " << size << " bytes" << std::endl;
        
        char buffer[5000];
        int readSize = 0;
        while(readSize < size){
            int tmp = min(5000, size - readSize);
            file.read(buffer, tmp);
            // cout << "read data: " << buffer << endl;
            filechunk.set_data(buffer, tmp);
            resp->Write(filechunk);
            readSize += tmp;
        }
       
        
    }
    file.close();
    resp->WritesDone();
    cout << "File sent successfuly " << response.message()<< endl;

    return "Success";

}


void ClientHelper::download(const string & filename){}