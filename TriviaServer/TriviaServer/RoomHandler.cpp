#include "RoomHandler.h"
#include "JsonResponsePacketSerializer.h"

#include "GetRoomStateRequest.h"
#include "GetRoomStateResponse.h"
//---------------------   constructor ----------------------------------------
RoomHandler::RoomHandler(RequestHandlerFactory* factory, Room room, LoggedUser user) :IRequestHandler(factory), _connectedUser(user)
{
	this->_connectedRoom = room;
}

RequestResult RoomHandler::getRoomState(RequestInfo info)
{
	GetRoomStateRequest req(info.getBuffer());
	bool actionResult = true;
	vector<string> users;
	bool isStarted = false;

	RequestResult res;
	try
	{
		isStarted = this->m_handlerFactory->getRoomManager().getRoomState(_connectedRoom.getID()) == ACTIVE;
		users = this->m_handlerFactory->getRoomManager().getPlayersInRoom(_connectedRoom.getID());
	}
	catch (std::exception e)
	{
		actionResult = false;
	}
	GetRoomStateResponse response((int)actionResult,isStarted,users,_connectedRoom.getQuestionAmount(),_connectedRoom.getQuestionTime());
	res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);
	if (actionResult)
		res.setNewHandler(nullptr);//this->m_handlerFactory->createMenuRequestHandler(_loggedUser.getUsername()));
	return res;
}