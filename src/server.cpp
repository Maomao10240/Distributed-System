#include <string>
#include <unistd.h>
#include <iostream>
#include "server.h"


using namespace std;
using grpc::ServerContext;
using grpc::ServerBuilder;


Server::Server(){}

Server::~Server(){}

string Server::RunServer(string path, string server_address){
    this->server_helper.setAddress(server_address);
    this->server_helper.Run(path);
    return "Success";

}
