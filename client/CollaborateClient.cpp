/*
 * ClientHandler.cpp
 *
 *  Created on: 2014Äê5ÔÂ29ÈÕ
 *      Author: huangqi
 */

#include "ClientHandler.h"
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

	std::map<std::string, PictureSDK*>::iterator it;
	for (it = m_handlerMap.begin(); it != m_handlerMap.end();)
	{
		PictureSDK* pSDK = it->second;
		if (NULL == pSDK)
		{
			delete pSDK;
			pSDK = NULL;
		}

		std::string sClientId = it->first;

		m_handlerMap.erase(it++);

		PRINT("Erase Client:%s", sClientId.c_str());
	}
}

void ClientHandler::action(std::string& _return, const UserInfo& user, const std::string& cmd, const std::string& params)
{

}

void ClientHandler::callback(const UserInfo& user, const std::string& event, const std::string& contents)
{

}

void ClientHandler::ping()
{
	PRINT("ping");
}

void* CreateServer(void* pArgs)
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
