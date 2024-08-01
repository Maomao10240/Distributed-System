#include "client.h"
#include <string>
#include <unistd.h>
#include <iostream>
#include <unordered_set>
#include <grpcpp/grpcpp.h>

using namespace std;

Client::Client(const shared_ptr<Channel> channel) : client_helper(channel){

}

Client::~Client(){}

string Client::Process(const string & command, const string & filename, const string & filepath){
    this->client_helper.setPath(filepath);
    if(command == "upload"){
        return this->client_helper.upload(filename);
    }else if(command == "download"){
        return this->client_helper.download(filename);
    }else if(command == "list"){
        return this->client_helper.list();
    }else if(command == "deletefile"){
        return this->client_helper.deleteFile(filename);
    }
    return "Failed";

}

