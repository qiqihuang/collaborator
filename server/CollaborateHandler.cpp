/*
 * CollaborateHandler.cpp
 *
 *  Created on: 2014Äê5ÔÂ29ÈÕ
 *      Author: huangqi
 */

#include "CollaborateHandler.h"
#include "Debug.h"
#include "Comm.h"
#include "json/json.h"
#include <boost/lexical_cast.hpp>

namespace huang
{
namespace collaborator
{

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

	do
	{
		Json::Reader reader;
		Json::Value root;
		if (!reader.parse(params, root, false))
		{
			_return = "0";

			EXCEPTION("Parse the params failed for User[%s]!!!", user.userId.c_str());

			break;
		}

		switch (cmdId)
		{
		case LOGIN:
		{
			int loginStatus = root["login_status"].asInt();

			std::map<std::string, UserInfo*>::iterator it = m_userMap.find(user.userId);
			if (m_userMap.end() == it)
			{
				Json::Value root;

				std::map<std::string, UserInfo*>::iterator iter;
				for (iter = m_userMap.begin(); iter != m_userMap.end(); iter++)
				{
					UserInfo* pUser = iter->second;
					if (NULL != pUser)
					{
						continue;
					}

					Json::Value contacts;
					contacts["userId"] = pUser->userId;
					contacts["sessionId"] = pUser->sessionId;
					contacts["info"] = pUser->info;

					root.append(contacts);
				}

				Json::FastWriter writer;
				_return = writer.write(root);//TODO Current version support all contacts only


				UserInfo* pUser = new UserInfo;
				pUser->userId = user.userId;
				pUser->sessionId = user.sessionId;
				pUser->info = "LOGGED";
				m_userMap.insert(make_pair(pUser->userId, pUser));

				PRINT("Login Success, userId[%s]", user.userId.c_str());

			}
			else
			{
				_return = "0";

				EXCEPTION("userId[%s] try to login Again!!!", user.userId.c_str());
			}

			PRINT("Login finish, m_userMap.size[%ld]", m_userMap.size());
		}
			break;
		case LOGOUT:
		{
			std::map<std::string, UserInfo*>::iterator it = m_userMap.find(user.userId);
			if (m_userMap.end() != it)
			{
				//TODO Broadcast to all contacts
				UserInfo* pUser = it->second;
				m_userMap.erase(it);

				if (NULL != pUser)
				{
					delete pUser;
					pUser = NULL;
				}

				PRINT("Logout Success, userId[%s]", user.userId.c_str());
				_return = "1";

			}
			else
			{
				EXCEPTION("userId[%s] try to logout Again!!!", user.userId.c_str());
				_return = "0";
			}

			PRINT("Logout finish, m_userMap.size[%ld]", m_userMap.size());
		}
			break;
		case CHANGESTATUS:
			break;
		default:
			break;
		}
	}
	while (false);

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

	}
	else
	{
		_return = "0";

		EXCEPTION("Couldn't found a handler for serve the userId[%s]!!!", user.userId.c_str());
	}

	PRINT("_return:%s", _return.c_str());
}

void CollaborateHandler::callback(const UserInfo& user, const int32_t eventId, const std::string& contents)
{
	return;
}

void CollaborateHandler::ping()
{
	PRINT("ping");
}

} /* namespace collaborator */
} /* namespace huang */
