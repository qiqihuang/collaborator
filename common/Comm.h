/*
 * Comm.h
 *
 *  Created on: 2014��6��4��
 *      Author: huangqi
 */

#ifndef COMM_H_
#define COMM_H_
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PlatformThreadFactory.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::concurrency;

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
	int LeasePort();
};

} /* namespace collaborator */
} /* namespace huang */

#endif /* COMM_H_ */
