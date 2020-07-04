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
class RoomAdminRequestHandler;
class RoomMemberRequestHandler;
class GameRequestHandler;
class RequestHandlerFactory
{
public:
	RequestHandlerFactory(IDatabase* database);
	LoginRequestHandler* createLoginRequestHandler();
	MenuRequestHandler* createMenuRequestHandler(string user);
	RoomAdminRequestHandler* createRoomAdminRequestHandler(int roomId, string user);
	RoomMemberRequestHandler* createRoomMemberRequestHandler(int roomId, string user);
	GameRequestHandler* createGameRquestHandler();


	LoginManager& getLoginManager();
	StatisticsManager& getStatisticsManager();
	RoomManager& getRoomManager();
	GameManager& getGameManager();

protected:
	LoginManager m_loginManger;
	RoomManager m_roomManager;
	StatisticsManager m_statsManager;
	IDatabase* m_database;
	//GameManager m_gameManager;
};