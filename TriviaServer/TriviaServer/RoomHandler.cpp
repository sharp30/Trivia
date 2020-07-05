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
	bool actionResult = true;
	vector<string> users;
	RoomState state = WAITNG;
	RequestResult res;
	try
	{
		state = this->m_handlerFactory->getRoomManager().getRoomState(_connectedRoom.getID());
		users = this->m_handlerFactory->getRoomManager().getPlayersInRoom(_connectedRoom.getID());
	}
	catch (std::exception e)
	{
		actionResult = false;
	}
	GetRoomStateResponse response((int)actionResult, state, users, _connectedRoom.getQuestionAmount(), _connectedRoom.getQuestionTime());
	res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);

	if (actionResult)
		if(state != ACTIVE)
			res.setNewHandler(nullptr);
		else if(!isAdmin())
		{
			int gameId = this->m_handlerFactory->getGameManager().getGameIdByRoomID(this->_connectedRoom.getID());
			res.setNewHandler((IRequestHandler*)this->m_handlerFactory->createGameRquestHandler(gameId, this->_connectedUser.getUsername()));
		}
	return res;

}