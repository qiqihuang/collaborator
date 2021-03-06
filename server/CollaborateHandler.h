/*
 * CollaborateHandler.h
 *
 *  Created on: 2014��5��29��
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
	void action(std::string& _return, const UserInfo& user, const int32_t cmdId, const std::string& params);

	void callback(const UserInfo& user, const int32_t eventId, const std::string& contents);

	void ping();

private:
	std::map<std::string, UserInfo*> m_userMap;
};

} /* namespace collaborator */
} /* namespace huang */

#endif /* COLLABORATEHANDLER_H_ */
