#include "MenuRequestHandler.h"
#include "JsonResponsePacketSerializer.h"
#include "GetStatisticsResponse.h"
#include "GetPlayersInRoomResponse.h"
#include "JoinRoomResponse.h"
#include "LogoutResponse.h"
#include "CreateRoomResponse.h"
#include "GetRoomsResponse.h"

//-----------------constructor---------
MenuRequestHandler::MenuRequestHandler(RequestHandlerFactory* factory) :IRequestHandler(factory)
{
}
//Empty for now
bool MenuRequestHandler::isRequestRelevant(RequestInfo info)
{
	return m_functions.find(info.getId()) != m_functions.end();
}

RequestResult MenuRequestHandler::handleRequest(RequestInfo info)
{

	return (this->*m_functions.at(info.getId()))(info);
}

RequestResult MenuRequestHandler::createRoom(RequestInfo info)
{
	CreateRoomRequest request(info.getBuffer());
	bool actionResult = true;
	RequestResult res;
	try
	{
		(this->m_handlerFactory->getRoomManager()).createRoom(request.getCreatorName());
	}
	catch(std::exception e)
	{
		actionResult = false;
	}
	CreateRoomResponse response((int)actionResult);
	res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);
	//res._newHandler 
}

RequestResult MenuRequestHandler::getRooms(RequestInfo info)
{
	GetRoomsResponse request(info.getBuffer());
	bool actionResult = true;
	RequestResult res;
	try
	{
		(this->m_handlerFactory->getRoomManager()).getRooms();
	}
	catch (std::exception e)
	{
		actionResult = false;
	}
	GetRoomsResponse response()
}

