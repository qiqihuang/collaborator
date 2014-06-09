/*
 * ClientHandler.cpp
 *
 *  Created on: 2014Äê5ÔÂ29ÈÕ
 *      Author: huangqi
 */

#include "CollaborateClient.h"
#include "Debug.h"
#include "json/json.h"
#include <boost/lexical_cast.hpp>

namespace huang
{
namespace collaborator
{

enum functionlist
{
	LOGIN = 1001,
	LOGOUT,
};

ClientHandler::ClientHandler()
{
	// TODO Auto-generated constructor stub
	m_spThreadManager = ThreadManager::newSimpleThreadManager(100);//temp worker count

	boost::shared_ptr<PlatformThreadFactory> threadFactory = boost::shared_ptr<PlatformThreadFactory>(new PlatformThreadFactory());
	m_spThreadManager->threadFactory(threadFactory);
	m_spThreadManager->start();

}

ClientHandler::~ClientHandler()
{
	m_spThreadManager->stop();

	std::map<std::string, UserInfo*>::iterator it;
	for (it = m_sessionMap.begin(); it != m_sessionMap.end();)
	{
		UserInfo* pUser = it->second;
		if (NULL == pUser)
		{
			delete pUser;
			pUser = NULL;
		}

		std::string sessionId = it->first;

		m_sessionMap.erase(it++);

		PRINT("Erase session:%s", sessionId.c_str());
	}
}

void ClientHandler::action(std::string& _return, const UserInfo& user, const int32_t cmdId, const std::string& params)
{

}

void ClientHandler::callback(const UserInfo& user, const int32_t eventId, const std::string& contents)
{

}

void ClientHandler::ping()
{
	PRINT("ping");
}

void* ClientHandler::CreateServer(void* pArgs)
{
	  ClientHandler* pThis = (ClientHandler *)pArgs;
	  if (NULL == pThis)
	  {
		  return NULL;
	  }

	  int nPort = Common::LeasePort();
	  boost::shared_ptr<TProcessor> processor(new collaborateProcessor(pThis->shared_from_this()));
	  boost::shared_ptr<TServerSocket> serverSocket(new TServerSocket(nPort));
	  boost::shared_ptr<TServerTransport> serverTransport(new TServerTransport(serverSocket));
	  boost::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
	  boost::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
	  boost::shared_ptr<ServerEventHandler> spEventHandler(new ServerEventHandler());

	  pThis->m_socketInfo = serverSocket->getSocketInfo();

	  pThis->m_spServer.reset(new TThreadedServer(processor, serverTransport, transportFactory, protocolFactory));
	  pThis->m_spServer->setServerEventHandler(spEventHandler);
	  pThis->m_spServer->serve();

	  PRINT("Server has gone !!!");

	  return NULL;
}

bool ClientHandler::StartServer()
{
	boost::shared_ptr<Task> task(new Task(CreateServer, this));
	m_spThreadManager->add(task);

	return true;
}

bool ClientHandler::StopServer()
{
	if (NULL != m_spServer.get())
	{
		m_spServer->stop();
	}

	return true;
}

std::string ClientHandler::GetSocketInfo()
{
	return m_socketInfo;
}

} /* namespace collaborator */
} /* namespace huang */
