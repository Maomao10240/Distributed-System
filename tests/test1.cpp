#include <gtest/gtest.h>
#include "../src/client.h"
#include "../src/server.h"
#include <grpcpp/grpcpp.h>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

// class ClientTest: public Client{
// public:
//     using Client::Client;
// };
bool AreFilesIdentical(const std::string& path1, const std::string& path2) {
    std::ifstream file1(path1, std::ios::binary);
    std::ifstream file2(path2, std::ios::binary);

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Error opening files." << std::endl;
        return false;
    }

    std::istreambuf_iterator<char> begin1(file1), end1;
    std::istreambuf_iterator<char> begin2(file2), end2;

    return std::equal(begin1, end1, begin2);
}

TEST(clientTest, Initialization){
    
    EXPECT_EQ(1, 1);
}

TEST(clientTest, Upload){

    shared_ptr<grpc::Channel> channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
    Client client(channel);
    string response = client.Process("upload", "1.jpg" , "../src/clientFile/");
    EXPECT_EQ(response, "Success");
}

TEST(serverTest, Upload){

    Server server;
    string path = "../serverFile/";;
    string server_address = "0.0.0.0:50051";
    string response = server.RunServer(path, server_address);
    std::string file1 = "../src/clientFile/1.jpg"; 
    std::string file2 = "../src/serverFile/1.jpg";  

    ASSERT_TRUE(fs::exists(file1)) << "File " << file1 << " does not exist.";
    ASSERT_TRUE(fs::exists(file2)) << "File " << file2 << " does not exist.";

    EXPECT_TRUE(AreFilesIdentical(file1, file2)) << "Files " << file1 << " and " << file2 << " are not identical.";
}