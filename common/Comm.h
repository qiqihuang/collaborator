/*
 * Comm.h
 *
 *  Created on: 2014年6月4日
 *      Author: huangqi
 */

#ifndef COMM_H_
#define COMM_H_

#include <netdb.h>
#include <arpa/inet.h>

namespace huang
{
namespace collaborator
{

enum functionlist
{
	LOGIN = 1001,
	LOGOUT,
	CHANGESTATUS
};

typedef void* (*TaskFn) (void *);

class Task : public Runnable
{
public:
	Task(TaskFn pFn, void* pArgs)
	{
		m_pFn = pFn;
		m_pArgs = pArgs;
	}
	~Task(){}

	void run()
	{
		m_pFn(m_pArgs);
	}

private:
	TaskFn m_pFn;
	void* m_pArgs;
};

class Comm
{
public:
	Comm();
	virtual ~Comm();

public:
	bool ThreadMaker()
	{
		pthread_t thread;

		pthread_attr_t attr;
		pthread_attr_init(&attr);
		//pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

		if (0 != pthread_create(&thread, &attr, DoEffectThread, NULL))
		{
			perror("pthread_create");
			printf("pthread_create failed, err:%s", strerror(errno));
		}


		/*for (int i=0; i<NUM_THREADS; i++)
		{
			pthread_join(threads[i], NULL);
		}*/

		//pthread_attr_destroy(&attr);
		//pthread_exit(NULL);

		return 0;
	}

	int LeasePort()
	{
		int nPort = -1;
		do
		{
			struct sockaddr_in addr;
			bzero(&addr, sizeof(addr));
			addr.sin_family = AF_INET;
			addr.sin_addr.s_addr = htons(INADDR_ANY);//自动获取本机地址
			addr.sin_port = htons(0);    //自动分配空闲端口

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

			getnameinfo(&addr, sizeof(addr), clienthost, sizeof(clienthost), clientservice, sizeof(clientservice), NI_NUMERICHOST | NI_NUMERICSERV);

			shutdown(nSocketFd, SHUT_RDWR);
			close(nSocketFd);

			nPort = std::atoi(clientservice);

			break;
		}
		while (true);

		return nPort;
	}
};

} /* namespace collaborator */
} /* namespace huang */

#endif /* COMM_H_ */
