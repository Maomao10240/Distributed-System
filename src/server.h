#include <string>
using namespace std;
#include "utils/serverhelper.h"

class Server{
protected:
    ServerHelper server_helper;
public:
    Server();
    ~Server();
    void RunServer(string server_address);
};