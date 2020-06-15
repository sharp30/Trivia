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


	static const int MSG_CODE = 15;
	static const int STATS_REQ_CODE = 70; // the message code of a getStatistics request

	LoggedUser m_user;
	static const std::map<int, handler_func> m_functions;

};
const std::map<int, MenuRequestHandler::handler_func> MenuRequestHandler::m_functions =
{
	{41	 , &MenuRequestHandler::createRoom},
	{43  , &MenuRequestHandler::getRooms},
	{45  , &MenuRequestHandler::joinRoom},
	{47  , &MenuRequestHandler::getPlayersInRoom},
	{71  , &MenuRequestHandler::getStatisticsRequest},
	{101 , &MenuRequestHandler::logout}
};
