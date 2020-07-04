#include "RoomAdminRequestHandler.h"
#include "JsonResponsePacketSerializer.h"

#include "StartGameResponse.h"
#include "CloseRoomResponse.h"
#include "GetRoomStateResponse.h"
#include "LeaveRoomResponse.h"


#include <thread>
//-----------------constructor------------------
RoomAdminRequestHandler::RoomAdminRequestHandler(RequestHandlerFactory* factory, LoggedUser connectedUser, Room connectedRoom) : RoomHandler(factory,connectedRoom,connectedUser)
{
}

bool RoomAdminRequestHandler::isRequestRelevant(RequestInfo req)
{
	int id = req.getId();
	return id == 48 || id == 50 || id == 52;
}

RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo req)
{
	if (req.getId() == 48)//getRoomState
		return getRoomState(req);

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
		res.setNewHandler(this->m_handlerFactory.)
	}
	else if (req.getId() == 52)// close
	{
		try
		{
			this->m_handlerFactory->getRoomManager().setRoomState(_connectedRoom.getID(), CLOSED); // -1 = Inactive // after X time delete the room
			std::thread t(&RoomManager::eraseRoom, &this->m_handlerFactory->getRoomManager(), this->_connectedRoom.getID());
			t.detach();
		}
		catch (std::exception e)
		{
			actionResult = false;
		}
		CloseRoomResponse resp((int)actionResult);
		res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&resp);
		if (actionResult)
			res.setNewHandler((IRequestHandler*)this->m_handlerFactory->createMenuRequestHandler(this->_connectedUser.getUsername()));
	}
	
	return res;  
}
