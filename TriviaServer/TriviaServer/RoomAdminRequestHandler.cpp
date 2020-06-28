#include "RoomAdminRequestHandler.h"
#include "JsonResponsePacketSerializer.h"

#include "StartGameResponse.h"
#include "CloseRoomResponse.h"
#include "GetRoomStateResponse.h"
#include "LeaveRoomResponse.h"

//-----------------constructor------------------
RoomAdminRequestHandler::RoomAdminRequestHandler(RequestHandlerFactory* factory, LoggedUser connectedUser, Room connectedRoom) : RoomHandler(factory,connectedRoom,connectedUser),_connectedUser(connectedUser)
{
	this->_connectedRoom = connectedRoom;
}

bool RoomAdminRequestHandler::isRequestRelevant(RequestInfo req)
{
	int id = req.getId();
	return id == 48 || id == 50 || id == 52;
}

RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo req)
{
	bool actionResult = true;
	RequestResult res;
	if (req.getId() == 50) // startRoom
	{
		try
		{
			this->m_handlerFactory->getRoomManager().setRoomState(_connectedRoom.getID(),ACTIVE);
		}
		catch (std::exception e)
		{
			actionResult = false;
		}
		StartGameResponse resp((int)actionResult);
		res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&resp);
	}
	if (req.getId() == 52)// close
	{
		try
		{
			this->m_handlerFactory->getRoomManager().setRoomState(_connectedRoom.getID(), CLOSED); // -1 = Inactive // after X time delete the room
		}
		catch (std::exception e)
		{
			actionResult = false;
		}
		CloseRoomResponse resp((int)actionResult);
		res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&resp);
	}
	//dual
	if (req.getId() == 54)//getRoomState
	{
		return getRoomState(req);
	}

	res.setNewHandler(nullptr);
	return res;  
}

