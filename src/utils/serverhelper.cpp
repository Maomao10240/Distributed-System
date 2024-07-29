#include "serverhelper.h"
#include <string>
#include <grpcpp/grpcpp.h>
#include <fstream>
#include <cstdio> 
#include <dirent.h>


using namespace std;
using grpc::ServerBuilder;
using grpc::ServerReader;
using grpc::ServerWriter;
using grpc::Status;
using service::FileChunk;
using service::Response;
using service::Request;
using service::Files;
using service::Empty;
using service::FileStatus;

class ServiceImpl final : public service::Dservice::Service{
    //virtual ::grpc::Status upload(::grpc::ServerContext* context, const ::service::FileChunk* request, ::service::Response* response);
    //stream virtual ::grpc::Status upload(::grpc::ServerContext* context, ::grpc::ServerReader< ::service::FileChunk>* reader, ::service::Response* response);

public:
    ServiceImpl(const string path): path_(path){};
    ~ServiceImpl(){};
    Status upload(ServerContext* context, ServerReader< FileChunk>* reader, Response* response) override{
        //1. get filename from metadata
        string filename;
        auto data = context->client_metadata();
        auto it = data.find("namekey");
        if(it != data.end()){
            filename =it->second.data();
            filename = this->path_ + filename;
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

   // virtual ::grpc::Status download(::grpc::ServerContext* context, const ::service::Request* request, ::grpc::ServerWriter< ::service::FileChunk>* writer);
    Status download(ServerContext* context, const Request* request, ServerWriter<FileChunk>* writer) override{
        FileChunk chunk;
        //1.get the filename
        string filename = request->name();
        filename = this->path_ + filename;
        fstream file = fstream(filename, ios::in|ios::binary);
        cout << "Filename requested:  "<<filename << endl;
        if(!file){
            cerr<<"File could not be opened"<<endl;
            return Status::CANCELLED;
        }else{
            cout << "File "<<filename<<" open successfuly" << endl;
            // Get the file size

            int size = std::filesystem::file_size(filename);
            std::cout << "Size of the data: " << size << " bytes" << std::endl;
            //2. write the file
            char buffer[5000];
            int readSize = 0;
            while(readSize < size){
                int tmp = min(5000, size - readSize);
                file.read(buffer, tmp);
                // cout << "read data: " << buffer << endl;
                chunk.set_data(buffer, tmp);
                writer->Write(chunk);
                readSize += tmp;
            }
        
            
        }
        file.close();
        return Status::OK;

    };

    //virtual ::grpc::Status list(::grpc::ServerContext* context, const ::service::Empty* request, ::service::Files* response);
    Status list(ServerContext* context, const Empty* request, Files* response) override{
        string path = this->path_;
        DIR* dir = opendir(path.c_str());
        struct dirent* entry;

        while ((entry = readdir(dir)) != nullptr) {
            // Skip the "." and ".." entries
            if (entry->d_name[0] == '.') continue;

            /*
              // Create and populate the first FileStatus
                FileStatus* file_status1 = files.add_file(); // Adds a new FileStatus to the repeated field
                file_status1->set_filename("example1.txt");

                // Create and populate the second FileStatus
                FileStatus* file_status2 = files.add_file(); // Adds another FileStatus to the repeated field
                file_status2->set_filename("example2.txt");
            */         

            FileStatus* filestatus = response->add_file();;
            filestatus->set_filename(entry->d_name);
        }
        closedir(dir);
        return Status::OK;

    }
    // virtual ::grpc::Status delete(::grpc::ServerContext* context, const ::service::Request* request, ::service::Response* response);
    Status deleteFile(ServerContext* context, const Request* request, Response* response) override{
        string filename = request->name();
        filename = this->path_ + filename;
        if(remove(filename.c_str()) == 0){
            response->set_message("File deleted!");
            return Status::OK;
        }
        return Status::CANCELLED;
    }

private:
    string path_;
};


ServerHelper::ServerHelper(){}

ServerHelper::~ServerHelper(){}





void ServerHelper::Run(string path){
    ServerBuilder builder;
    ServiceImpl service(path);
    builder.AddListeningPort(this->server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    this->server = builder.BuildAndStart();
    this->server->Wait();
    cout<<"Sever start listening ......................." <<endl;
}



void ServerHelper::setAddress(string address){
    this->server_address = address;
}
