/*
 * CollaborateHandler.h
 *
 *  Created on: 2014Äê5ÔÂ29ÈÕ
 *      Author: huangqi
 */

#ifndef COLLABORATEHANDLER_H_
#define COLLABORATEHANDLER_H_

#include "collaborate.h"

namespace huang
{
namespace collaborator
{

class CollaborateHandler: virtual public collaborateIf
{

public:
	CollaborateHandler();
	virtual ~CollaborateHandler();

public:
	void action(std::string& _return, const UserInfo& user, const std::string& cmd, const std::string& params);

	void callback(const UserInfo& user, const std::string& event, const std::string& contents);

	void ping();

private:
	std::map<std::string, PictureSDK*> m_handlerMap;
};

} /* namespace collaborator */
} /* namespace huang */

#endif /* COLLABORATEHANDLER_H_ */
