// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "collaborate.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::huang::collaborator;

class collaborateHandler : virtual public collaborateIf {
 public:
  collaborateHandler() {
    // Your initialization goes here
  }

  void action(std::string& _return, const UserInfo& user, const std::string& cmd, const std::string& params) {
    // Your implementation goes here
    printf("action\n");
  }

  void callback(const UserInfo& user, const std::string& event, const std::string& contents) {
    // Your implementation goes here
    printf("callback\n");
  }

  void ping() {
    // Your implementation goes here
    printf("ping\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<collaborateHandler> handler(new collaborateHandler());
  shared_ptr<TProcessor> processor(new collaborateProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

