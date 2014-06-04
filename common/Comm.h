/*
 * Comm.h
 *
 *  Created on: 2014年6月4日
 *      Author: huangqi
 */

#ifndef COMM_H_
#define COMM_H_

namespace huang
{
namespace collaborator
{

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
			bzero(&addr, sizeof(client_addr)); //把一段内存区的内容全部设置为0
			addr.sin_family = AF_INET;    //internet协议族
			addr.sin_addr.s_addr = htons(INADDR_ANY);    //INADDR_ANY表示自动获取本机地址
			addr.sin_port = htons(0);    //0表示让系统自动分配一个空闲端口
			//创建用于internet的流协议(TCP)socket,用client_socket代表客户机socket
			int socket = socket(AF_INET, SOCK_STREAM, 0);

			if (socket < 0)
			{
				printf("Create Socket Failed!\n");
				continue;
			}
			//把客户机的socket和客户机的socket地址结构联系起来
			if (bind(socket, (struct sockaddr*) &addr, sizeof(addr)))
			{
				printf("Bind %u Failed!\n", addr);
				continue;
			}

			close(socket);

			nPort = addr.sin_port;

			break;
		}
		while (true);

		return nPort;
	}
};

} /* namespace collaborator */
} /* namespace huang */

#endif /* COMM_H_ */
