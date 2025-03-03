#include <string>
#include "../protoSrc/service.grpc.pb.h"
using namespace std;
using grpc::Channel;


class ClientHelper{
public:
    ClientHelper(const shared_ptr<Channel> channel);
    ~ClientHelper();
    string upload(const string & filename);
    string download(const string & filename);
    string list();
    string deleteFile(const string & filename);
    void setPath(string path);

protected:
    unique_ptr<service::Dservice::Stub> stub_;
    string path_;
};