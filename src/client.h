#include <string>
using namespace std;
#include "utils/clienthelper.h"

class Client{
protected:
    ClientHelper client_helper;
public:
    Client(const shared_ptr<Channel> channel);
    ~Client();
    void Process(const string & command, const string & filename, const string & filepath);
};