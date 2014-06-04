// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "collaborate.h"
#include "CollaborateClient.h"
#include "Debug.h"
#include <sys/time.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::huang::collaborator;

int main(int argc, char **argv)
{
	boost::shared_ptr<ClientHandler> clientHandler(new CollaborateClient());
	clientHandler->StartServer();
	std::string socketInfo = clientHandler->GetSocketInfo();

	boost::shared_ptr<TTransport> socket(new TSocket("localhost", 19090));
	boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
	collaborateClient client(protocol);
	transport->open();

	std::string strRet;
	std::string strLoginParams;
	client.action(strRet, "LOGIN", "HIDE");
	transport->close();

	return 0;
}

