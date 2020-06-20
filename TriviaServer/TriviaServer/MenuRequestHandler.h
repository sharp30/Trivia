#pragma once

#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"
//#include "StatisticsManager.h"
#include "CreateRoomRequest.h"
#include "JoinRoomRequest.h"
#include "GetPlayersInRoomRequest.h"
//class RequestHandlerFactory;

class MenuRequestHandler : IRequestHandler
{
public:
	MenuRequestHandler(RequestHandlerFactory* factory,LoggedUser user);
	virtual bool isRequestRelevant(RequestInfo);
	virtual RequestResult handleRequest(RequestInfo);
	using handler_func = RequestResult(MenuRequestHandler::*)(RequestInfo);

protected:
	RequestResult createRoom(RequestInfo info);
	RequestResult getRooms(RequestInfo info);
	RequestResult joinRoom(RequestInfo info);
	RequestResult getPlayersInRoom(RequestInfo info);
	RequestResult getStatisticsRequest(RequestInfo info);
	RequestResult logout(RequestInfo info);


	static map<string, int> MSG_CODES;
	static map<string, int> initMsgCodes()
	{
		map<string, int> m;
		m["CREATE_ROOM"] = 40;
		m["JOIN_ROOM"] = 44;
		m["GET_STATS"] = 70;
		m["LOGOUT"] = 100;

		return m;
	};

	LoggedUser m_user;
	static const std::map<int, handler_func> m_functions;

};
const std::map<int, MenuRequestHandler::handler_func> MenuRequestHandler::m_functions =
{
	{40 , &MenuRequestHandler::createRoom},
	{42, &MenuRequestHandler::getRooms},
	{44 , &MenuRequestHandler::joinRoom},
	{46 , &MenuRequestHandler::getPlayersInRoom},
	{70, &MenuRequestHandler::getStatisticsRequest},
	{100, &MenuRequestHandler::logout}
};
