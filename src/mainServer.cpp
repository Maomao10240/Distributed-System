#include <string>
#include <unistd.h>
#include <iostream>
#include "server.h"


int main(int argc, char** argv){
    Server server;
    string path = "../src/serverFile/";;
    string server_address = "0.0.0.0:50051";
    string command = "";
    int opt;

    while((opt = getopt(argc, argv, "f:p:h")) != -1){
        switch(opt){
            case 'p':
                path = optarg;
                break;
            case 'h':
                server_address = optarg;
                break;
            default:
                return 1;
        }
    }
    cout << "Path: " << path << endl;
    cout << "Server Address: " << server_address << endl;
    server.RunServer(path, server_address);
    return 0;
}