#include "../protoSrc/service.grpc.pb.h"

using grpc::ServerContext;
using service::FileChunk;
using service::Response;
using grpc::Status;
using namespace std;

class ServerHelper{
public:
    ServerHelper();
    ~ServerHelper();
    void Run();

    void setAddress(string address);
private:
    unique_ptr<grpc::Server> server;
    string server_address;
};