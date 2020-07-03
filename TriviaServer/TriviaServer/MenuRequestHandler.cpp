#include "MenuRequestHandler.h"
#include "JsonResponsePacketSerializer.h"
#include "GetStatisticsResponse.h"
#include "GetRoomStateResponse.h"
#include "GetPlayersInRoomResponse.h"
#include "JoinRoomResponse.h"
#include "LogoutResponse.h"
#include "CreateRoomResponse.h"
#include "GetRoomsResponse.h"
#include "BestScoresResponse.h"

const std::map<int, MenuRequestHandler::handler_func> MenuRequestHandler::m_functions =
{
	{40 , &MenuRequestHandler::createRoom},
	{42, &MenuRequestHandler::getRooms},
	{44 , &MenuRequestHandler::joinRoom},
	{46 , &MenuRequestHandler::getPlayersInRoom},
	{70, &MenuRequestHandler::getStatisticsRequest},
	{74, &MenuRequestHandler::getBestScores},
	{100, &MenuRequestHandler::logout}
};


//-----------------constructor--------------------
MenuRequestHandler::MenuRequestHandler(RequestHandlerFactory* factory ,LoggedUser user) :IRequestHandler(factory), m_user(user)
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
	int id = 0;
	try
	{
		/*
		(this->m_handlerFactory->getRoomManager()).createRoom(m_user.getUsername(), request.getRoomName(), request.getMaxUsers(),
			request.getAnswerTimeOut(), request.getQuestionCount());
		*/
		id = (this->m_handlerFactory->getRoomManager()).createRoom(m_user.getUsername(),request.getRoomName(),request.getMaxUsers(),request.getAnswerTimeOut(),request.getQuestionCount());
	}
	catch(std::exception e)
	{
		actionResult = false;
	}

	CreateRoomResponse response((int)actionResult);
	res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);
	if (actionResult)
		res.setNewHandler((IRequestHandler*)this->m_handlerFactory->createRoomAdminRequestHandler(id,m_user.getUsername()));
	return res;
}

RequestResult MenuRequestHandler::getRooms(RequestInfo info)
{
	bool actionResult = true;
	vector<Room> rooms;
	RequestResult res;
	try
	{
		rooms = (this->m_handlerFactory->getRoomManager()).getRooms();
	}
	catch (std::exception e)
	{
		actionResult = false;
	}
	GetRoomsResponse response((int)actionResult, rooms);
	res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);
	if (actionResult)
		res.setNewHandler(this->m_handlerFactory->createMenuRequestHandler(m_user.getUsername()));
	return res;
}

RequestResult MenuRequestHandler::joinRoom(RequestInfo info)
{
	JoinRoomRequest req(info.getBuffer());
	bool actionResult = true;
	RequestResult res;
	try 
	{
		this->m_handlerFactory->getRoomManager().addPlayerToRoom(req.getRoomId(),this->m_user.getUsername());
	}
	catch (std::exception e)
	{
		actionResult = false;
	}

	JoinRoomResponse response((int)actionResult);
	res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);

	if (actionResult)
		res.setNewHandler((IRequestHandler*)this->m_handlerFactory->createRoomMemberRequestHandler(req.getRoomId(),m_user.getUsername()));
	return res;
}

RequestResult MenuRequestHandler::getPlayersInRoom(RequestInfo info)
{
	GetPlayersInRoomRequest req(info.getBuffer());
	bool actionResult = true;
	vector<string> users;
	RequestResult res;
	try
	{
		users = this->m_handlerFactory->getRoomManager().getPlayersInRoom(req.getRoomId());
	}
	catch (std::exception e)
	{
		actionResult = false;
	}
	GetPlayersInRoomResponse response(users);
	res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);
	if (actionResult)
		res.setNewHandler(this->m_handlerFactory->createMenuRequestHandler(m_user.getUsername()));
	return res;
}


RequestResult MenuRequestHandler::getStatisticsRequest(RequestInfo info)
{
	bool actionResult = true;
	std::map<string,string> data;
	RequestResult res;
	try
	{
		data = this->m_handlerFactory->getStatisticsManager().getStatistics(m_user.getUsername());

	}
	catch (std::exception e)
	{
		actionResult = false;
	}

	GetStatisticsResponse response((int)actionResult, data);
	res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);

	if (actionResult)
		res.setNewHandler(this->m_handlerFactory->createMenuRequestHandler(m_user.getUsername()));
	return res;
}

RequestResult MenuRequestHandler::logout(RequestInfo info)
{
	bool actionResult = true;
	RequestResult res;

	try
	{
		this->m_handlerFactory->getLoginManager().logout(this->m_user.getUsername());
	}
	catch (std::exception e)
	{
		actionResult = false;
	}

	LogoutResponse response((int)actionResult);

	res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);
	
	if (actionResult)
		res.setNewHandler((IRequestHandler*)this->m_handlerFactory->createLoginRequestHandler());

	return res;
}

RequestResult MenuRequestHandler::getBestScores(RequestInfo info)
{
	RequestResult res;
	vector<string> data;
	bool actionResult = true;
	try
	{
		data = this->m_handlerFactory->getStatisticsManager().getBestPlayers();
	}
	catch (std::exception e)
	{
		actionResult = false;
	}
	BestScoresResponse response((int)actionResult, data);

	res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);

	if (actionResult)
		res.setNewHandler(this->m_handlerFactory->createMenuRequestHandler(m_user.getUsername()));

	return res;
}
