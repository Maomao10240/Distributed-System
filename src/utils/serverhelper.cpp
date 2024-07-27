#include "serverhelper.h"
#include <string>
#include <grpcpp/grpcpp.h>
#include <fstream>

using namespace std;
using grpc::ServerBuilder;
using grpc::ServerReader;
using grpc::Status;
using service::FileChunk;
using service::Response;

class ServiceImpl final : public service::Dservice::Service{
    //virtual ::grpc::Status upload(::grpc::ServerContext* context, const ::service::FileChunk* request, ::service::Response* response);
    //stream virtual ::grpc::Status upload(::grpc::ServerContext* context, ::grpc::ServerReader< ::service::FileChunk>* reader, ::service::Response* response);

public:
    ServiceImpl(){};
    ~ServiceImpl(){};
    Status upload(ServerContext* context, ServerReader< FileChunk>* reader, Response* response) override{
        //1. get filename from metadata
        string filename;
        auto data = context->client_metadata();
        auto it = data.find("namekey");
        if(it != data.end()){
            filename =it->second.data();
            filename = "serverFile/" + filename;
            cout << "Get the filename: " << filename <<endl;
        }
        //2. read the file
        ofstream of;
        FileChunk chunk;
        int total;
        while(reader->Read(&chunk)){
            cout<<"Start reading--------------------- "<<endl;

            if(!of.is_open()){
                of.open(filename);
            }
            const string & str = chunk.data();
            cout<<"data reading size " << str.size()<<endl;
            total += str.size();
            of << str;
        }
        of.close();
        response->set_message("File saved!");
        
        return Status::OK;
    }
};


ServerHelper::ServerHelper(){}

ServerHelper::~ServerHelper(){}





void ServerHelper::Run(){
    ServerBuilder builder;
    ServiceImpl service;
    builder.AddListeningPort(this->server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    this->server = builder.BuildAndStart();
    this->server->Wait();
    cout<<"Sever start listening ......................." <<endl;
}



void ServerHelper::setAddress(string address){
    this->server_address = address;
}
