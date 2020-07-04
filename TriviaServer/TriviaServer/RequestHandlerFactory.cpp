#include "RequestHandlerFactory.h"
#include "LoginRequestHandler.h"
#include "MenuRequestHandler.h"
#include "RoomAdminRequestHandler.h"
#include "RoomMemberRequestHandler.h"
#include "GameRequestHandler.h"
/*-------------------------------Creating function---------------------------------
Important Note : The function  allcoates dinamically beacuse this is the only option to return pointer of object that was created in a function.
Moreover we don't have interest of returning by value/*


/*
This function creates an LoginRequestHandler on the heap memory and returns it's address
Input:None
Output:The address of the instance :LoginRequestHandler*
*/
RequestHandlerFactory::RequestHandlerFactory(IDatabase* database) : m_database(database),m_loginManger(database),m_statsManager(database)
{
}
LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
	return new LoginRequestHandler(this);
}

/*
This function creates an MenuRequestHandler on the heap memory and returns it's address
Input:None
Output:The address of the instance :MenuRequestHandler*
*/
MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandler(string user)
{
	return new MenuRequestHandler(this,LoggedUser(user));
}
/*
This function creates an RoomAdminRequestHandler on the heap memory and returns it's address
Input:None
Output:The address of the instance :MenuRequestHandler*
*/
RoomAdminRequestHandler* RequestHandlerFactory::createRoomAdminRequestHandler(int roomId, string user)
{
	try
	{
		return new RoomAdminRequestHandler(this, LoggedUser(user), m_roomManager.getRoom(roomId));
	}
	//if room doesn't exist
	catch (std::exception e) 
	{
		return nullptr;
	}
}

RoomMemberRequestHandler* RequestHandlerFactory::createRoomMemberRequestHandler(int roomId, string user)
{
	try
	{
		return new RoomMemberRequestHandler(this, LoggedUser(user), m_roomManager.getRoom(roomId));
	}
	//if room doesn't exist
	catch (std::exception e)
	{
		return nullptr;
	}
}

GameRequestHandler* RequestHandlerFactory::createGameRquestHandler()
{
	return new GameRequestHandler(this,)
}


/*
This function returns reference to the login Manager
Input:None
Output:reference to the login manager
*/
LoginManager& RequestHandlerFactory::getLoginManager()
{
	return this->m_loginManger;
}
/*
This function returns reference to the statistics Manager
Input:None
Output:reference to the login manager
*/
StatisticsManager& RequestHandlerFactory::getStatisticsManager()
{
	return this->m_statsManager;
}
/*
This function returns reference to the Room Manager
Input:None
Output:reference to the login manager
*/
RoomManager& RequestHandlerFactory::getRoomManager()
{
	return this->m_roomManager;
}
