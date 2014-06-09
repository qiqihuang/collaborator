/*
 * ServerEventHandler.h
 *
 *  Created on: 2014Äê6ÔÂ9ÈÕ
 *      Author: huangqi
 */

#ifndef SERVEREVENTHANDLER_H_
#define SERVEREVENTHANDLER_H_

#include "Debug.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TThreadedServer.h>
//#include <thrift/transport/TSocket.h> //for solve ‘sigevent’ is ambiguous
#include <thrift/transport/TBufferTransports.h>
#include <thrift/concurrency/PlatformThreadFactory.h>
#include <sys/time.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

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

class ServerEventHandler : public server::TServerEventHandler
{
public:

	/**
	 * Called before the server begins.
	 */
	void preServe()
	{
		PRINT("Server is about Starting");
	}

	/**
	 * Called when a new client has connected and is about to being processing.
	 */
	void* createContext(boost::shared_ptr<TProtocol> input, boost::shared_ptr<TProtocol> output)
	{
		(void) input;
		(void) output;

		PRINT("Server createContext");
		gettimeofday(&start, NULL);
		return NULL;
	}

	/**
	 * Called when a client has finished request-handling to delete server
	 * context.
	 */
	void deleteContext(void* serverContext, boost::shared_ptr<TProtocol> input, boost::shared_ptr<TProtocol> output)
	{
		(void) serverContext;
		(void) input;
		(void) output;

		PRINT("Server deleteContext");
		gettimeofday(&end, NULL);

		unsigned long dTime = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
		PRINT("Process time %ld", dTime);
	}

	/**
	 * Called when a client is about to call the processor.
	 */
	void processContext(void* serverContext, boost::shared_ptr<TTransport> transport)
	{
		(void) serverContext;
		(void) transport;

		PRINT("Server processContext");
	}

private:
	struct timeval start;
	struct timeval end;

};
} /* namespace collaborator */
} /* namespace huang */

#endif /* SERVEREVENTHANDLER_H_ */
