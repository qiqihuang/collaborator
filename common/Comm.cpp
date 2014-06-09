/*
 * Comm.cpp
 *
 *  Created on: 2014年6月4日
 *      Author: huangqi
 */

#include "Comm.h"
#include "Debug.h"
#include <string.h>
#include <thrift/transport/TSocket.h>

namespace huang
{
namespace collaborator
{

Comm::Comm()
{
	// TODO Auto-generated constructor stub

}

Comm::~Comm()
{
	// TODO Auto-generated destructor stub
}

int Comm::LeasePort()
{
	int nPort = -1;
	do
	{
		struct sockaddr_in addr;
		bzero(&addr, sizeof(addr));
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = htons(INADDR_ANY);
		addr.sin_port = htons(0);

		int nSocketFd = socket(AF_INET, SOCK_STREAM, 0);
		if (socket < 0)
		{
			PRINT("Socket Create Failed!");
			continue;
		}

		int nFlag = 1;
		setsockopt(nSocketFd, SOL_SOCKET, SO_REUSEADDR, &nFlag, sizeof(nFlag));

		if (-1 == bind(nSocketFd, (struct sockaddr *)&addr, sizeof(addr)))
		{
			PRINT("Socket Bind Failed!");

			shutdown(nSocketFd, SHUT_RDWR);
			close(nSocketFd);

			continue;
		}

		char clienthost[NI_MAXHOST];
		char clientservice[NI_MAXSERV];

		getnameinfo((sockaddr *)&addr, sizeof(struct sockaddr), clienthost, sizeof(clienthost), clientservice, sizeof(clientservice), NI_NUMERICHOST | NI_NUMERICSERV);

		shutdown(nSocketFd, SHUT_RDWR);
		close(nSocketFd);

		nPort = std::atoi(clientservice);

		break;
	}
	while (true);

	return nPort;
}

} /* namespace collaborator */
} /* namespace huang */
