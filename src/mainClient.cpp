#include <iostream>
#include <unordered_set>
#include <grpcpp/grpcpp.h>
#include <string>
#include <unistd.h>
#include "client.h"

using namespace std;

//argc is the count of command-line arguments, and argv is an array of C-style strings representing these arguments.
int main(int argc, char** argv){
    shared_ptr<grpc::Channel> channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());

    Client client(channel);
    string filepath = "../src/clientFile/";
    string filename = "1.txt";
    string path = "client_path";
    string server_address = "0.0.0.0:50051";
    string command = "";
    int opt;
    //With Colon (f:): Options followed by a colon require an argument. When getopt() encounters such an option, it expects the next command-line argument to be the value for this option.
    while((opt = getopt(argc, argv, "f:p:h")) != -1){
        switch(opt){
            case 'f':
                filename = optarg;
                break;
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
    cout << "Filename: " << filename << endl;
    cout << "Path: " << path << endl;
    cout << "Server Address: " << server_address << endl;

    //get command line run: ./client -f "2.txt" COMMAND upload
    unordered_set<string> commands;
    commands.insert("upload");
    commands.insert("download"); 
    commands.insert("list");
    commands.insert("deletefile");


    if(optind < argc){
        command = argv[optind+1];
        cout << "Optind: " << optind << " argc: " <<argc << endl;
        cout << "Command: " << command << endl;
        auto it = commands.find(command);
        if(it != commands.end()){
            client.Process(command, filename, filepath);
        }else{
            cout << "Wrong Command!" << endl;
            return -1;
        }
    }
     


}