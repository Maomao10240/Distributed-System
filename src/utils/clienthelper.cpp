#include "clienthelper.h"
#include "../protoSrc/service.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <fstream>

using namespace std;
using service::FileChunk;
using service::Response;
using service::Request;
using grpc::ClientContext;
using grpc::Status;
using service::Empty;
using service::Files;
using service::FileStatus;


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
    cerr<<"File " <<filenm << "start"<<endl;
    if(!file){
        cerr<<"File " <<filenm << " could not be opened"<<endl;
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


string ClientHelper::download(const string & filename){
    FileChunk chunk;
    Request request;
    ClientContext context;
    //context.AddMetadata("namekey", filename);
    request.set_name(filename);
    string filenameUpdate = this->path_ + filename;
    unique_ptr< ::grpc::ClientReader< FileChunk>> file = stub_->download(&context, request);
    ofstream of;
    int total;
    while(file->Read(&chunk)){
        cout<<"Start downloading--------------------- "<<endl;

        if(!of.is_open()){
            of.open(filenameUpdate);
        }
        const string & str = chunk.data();
        cout<<"data reading size " << str.size()<<endl;
        total += str.size();
        of << str;
    }
    of.close();
    return "success";



}

string ClientHelper::list(){
    ClientContext context;
    Empty empty;
    Files files;
//    virtual ::grpc::Status list(::grpc::ClientContext* context, const ::service::Empty& request, ::service::Files* response) = 0;
    Status status = this->stub_->list(&context, empty, &files);
    for(const FileStatus & f: files.file()){
        cout << "List file name : " << f.filename() << endl;
    }
    return "success";

}
string ClientHelper::deleteFile(const string & filename){
    ClientContext context;
    Request request;
    Response response;
    request.set_name(filename);
//    virtual ::grpc::Status deleteFile(::grpc::ClientContext* context, const ::service::Request& request, ::service::Response* response) = 0;
    Status status = this->stub_->deleteFile(&context, request, &response);
    cout << "Result: " << response.message() <<endl;
    return "success";

}