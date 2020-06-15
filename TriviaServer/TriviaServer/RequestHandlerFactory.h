#pragma once

//#include "LoginRequestHandler.h"
//#include "MenuRequestHandler.h"
#include "LoginManager.h"
#include "IDatabase.h"
#include "RoomManager.h"
#include "StatisticsManager.h"

class IRequestHandler;
class MenuRequestHandler;
class LoginRequestHandler;

class RequestHandlerFactory
{
public:
	RequestHandlerFactory(IDatabase* database);
	LoginRequestHandler* createLoginRequestHandler();
	MenuRequestHandler* createMenuRequestHandler(string user);
	LoginManager& getLoginManager();
	StatisticsManager& getStatisticsManager();
	RoomManager& getRoomManager();

protected:
	LoginManager m_loginManger;
	RoomManager m_roomManager;
	StatisticsManager m_statsManager;
	IDatabase* m_database;
};