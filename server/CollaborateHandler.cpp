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

void CollaborateHandler::action(std::string& _return, const UserInfo& user, const std::string& cmd, const std::string& params)
{

}

void CollaborateHandler::callback(const UserInfo& user, const std::string& event, const std::string& contents)
{

}

void CollaborateHandler::ping()
{
	PRINT("ping");
}

} /* namespace collaborator */
} /* namespace huang */
