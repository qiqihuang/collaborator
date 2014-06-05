/*
 * CollaborateHandler.cpp
 *
 *  Created on: 2014Äê5ÔÂ29ÈÕ
 *      Author: huangqi
 */

#include "CollaborateHandler.h"
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

CollaborateHandler::CollaborateHandler()
{
	// TODO Auto-generated constructor stub

}

CollaborateHandler::~CollaborateHandler()
{
	std::map<std::string, UserInfo*>::iterator it;
	for (it = m_userMap.begin(); it != m_userMap.end();)
	{
		UserInfo* pUser = it->second;
		if (NULL == pUser)
		{
			delete pUser;
			pUser = NULL;
		}

		std::string sUserId = it->first;

		m_userMap.erase(it++);

		PRINT("Erase User:%s", sUserId.c_str());
	}
}

void CollaborateHandler::action(std::string& _return, const UserInfo& user, const int32_t cmdId, const std::string& params)
{
	PRINT("userId:%s", user.userId.c_str());
	PRINT("sessionId:%s", user.sessionId.c_str());
	PRINT("info:%s", user.info.c_str());

	PRINT("cmdId:%d", cmdId);
	PRINT("params:%s", params.c_str());

	std::map<std::string, UserInfo*>::iterator it = m_userMap.find(user.userId);
	if (m_userMap.end() != it)
	{
		UserInfo* pUser = it->second;
		if (NULL == pUser)
		{
			_return = "0";

			EXCEPTION("The handler is NULL for User[%s]!!!", user.userId.c_str());

			//m_mutex.unlock();
			return;
		}

		do
		{
			Json::Reader reader;
			Json::Value root;
			if (!reader.parse(params, root, false))
			{
				_return = "0";

				EXCEPTION("Parse the params failed for ClientId[%s]!!!", clientId.c_str());

				break;
			}

			switch (cmdId)
			{
			case LOGIN:
			{
				int loginStatus = (StatusT)(root["login_status"].asInt());

				std::map<std::string, UserInfo*>::iterator it = m_userMap.find(clientId);
				if (m_userMap.end() == it)
				{
					UserInfo* pUser = new UserInfo;
					pUser->userId = user.userId;
					pUser->sessionId = user.sessionId;
					pUser->info = "LOGGED";

					m_userMap.insert(make_pair(pUser->userId, pUser));

					_return = "LOGGED";//TODO

					PRINT("Login Success, userId[%s]", pUser->userId.c_str());

				}
				else
				{
					_return = "0";

					EXCEPTION("userId[%s] try to login Again!!!", pUser->userId.c_str());
				}
				PRINT("Login finish, m_userMap.size[%ld]", m_userMap.size());
			}
				break;
			case LOGOUT:
				break;
			case CHANGESTATUS:
				break;
			default:
				break;
			}
		}
		while (false);

	}
	else
	{
		_return = "0";

		EXCEPTION("Couldn't found a handler for serve the userId[%s]!!!", user.userId.c_str());
	}

	PRINT("_return:%s", _return.c_str());
}
}

void CollaborateHandler::callback(const UserInfo& user, const int32_t eventId, const std::string& contents)
{

}

void CollaborateHandler::ping()
{
	PRINT("ping");
}

} /* namespace collaborator */
} /* namespace huang */
