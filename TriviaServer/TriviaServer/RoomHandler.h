#pragma once

#include "IRequestHandler.h"

class RoomHandler :public IRequestHandler
{
public:
	RoomHandler(RequestHandlerFactory* factory, Room room, LoggedUser user);

	

protected:
	RequestResult getRoomState(RequestInfo info);

	
	Room _connectedRoom;
	LoggedUser _loggedUser;

};