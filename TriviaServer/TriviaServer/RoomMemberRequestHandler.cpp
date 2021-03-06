#include "RoomMemberRequestHandler.h"
#include "LeaveRoomResponse.h"
#include "JsonResponsePacketSerializer.h"
#include "LogoutResponse.h"


RoomMemberRequestHandler::RoomMemberRequestHandler(RequestHandlerFactory* factory, LoggedUser user, Room connectedRoom) : RoomHandler(factory,connectedRoom,user)
{
}

bool RoomMemberRequestHandler::isRequestRelevant(RequestInfo info)
{
	int id = info.getId();
	return id == 48 || id == 54 || id == 100;
}

RequestResult RoomMemberRequestHandler::handleRequest(RequestInfo info)
{
	if (info.getId() == 48)
		return getRoomState(info);
	if (info.getId() == 100)
		return logout(info);

	//leave room
	bool actionResult = true;
	RequestResult res;
	try
	{
		this->m_handlerFactory->getRoomManager().RemovePlayerFromRoom(this->_connectedRoom.getID(), this->_connectedUser.getUsername());
	}
	catch (std::exception e)
	{
		actionResult = false;
	}
	LeaveRoomResponse resp((int)actionResult);
	res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&resp);
	if (actionResult)
		res.setNewHandler((IRequestHandler*)this->m_handlerFactory->createMenuRequestHandler(this->_connectedUser.getUsername()));

	return res;
}

RequestResult RoomMemberRequestHandler::logout(RequestInfo info)
{
	bool actionResult = true;
	RequestResult res;

	try
	{
		this->m_handlerFactory->getLoginManager().logout(this->_connectedUser.getUsername());
		this->m_handlerFactory->getRoomManager().RemovePlayerFromRoom(this->_connectedRoom.getID(), this->_connectedUser.getUsername());
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

bool RoomMemberRequestHandler::isAdmin()
{
	return false;
}
