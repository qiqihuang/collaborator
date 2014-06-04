/*
 * ClientHandler.h
 *
 *  Created on: 2014Äê5ÔÂ29ÈÕ
 *      Author: huangqi
 */

#ifndef CLIENTHANDLER_H_
#define CLIENTHANDLER_H_

#include "collaborate.h"
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PlatformThreadFactory.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::concurrency;

namespace huang
{
namespace collaborator
{

class ClientHandler: virtual public collaborateIf,  public boost::enable_shared_from_this<ClientHandler>
{

public:
	ClientHandler();
	virtual ~ClientHandler();

public:
	void action(std::string& _return, const UserInfo& user, const std::string& cmd, const std::string& params);

	void callback(const UserInfo& user, const std::string& event, const std::string& contents);

	void ping();

public:
	bool StartServer();
	bool StopServer();


	std::string GetSocketInfo();

private:
	std::map<std::string, PictureSDK*> m_sessionMap;
	boost::shared_ptr<ThreadManager> m_spThreadManager;
	boost::shared_ptr<TServer> m_spServer;

	std::string m_socketInfo;
};

} /* namespace collaborator */
} /* namespace huang */

#endif /* CLIENTHANDLER_H_ */
