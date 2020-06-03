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
	MenuRequestHandler(RequestHandlerFactory* factory);
	virtual bool isRequestRelevant(RequestInfo);
	virtual RequestResult handleRequest(RequestInfo);
	using handler_func = RequestResult(MenuRequestHandler::*)(RequestInfo);
	//why is typedef doesn't work
protected:
	RequestResult createRoom(RequestInfo);
	RequestResult getRooms(RequestInfo);
	RequestResult joinRoom(RequestInfo);
	RequestResult getPlayersInRoom(RequestInfo);
	RequestResult getStatisticsRequest(RequestInfo);
	RequestResult logout(RequestInfo);


	static const int MSG_CODE = 15;
	static const int STATS_REQ_CODE = 70; // the message code of a getStatistics request

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
