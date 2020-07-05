#pragma once

#include "IRequestHandler.h"

class RoomHandler :public IRequestHandler
{
public:
	RoomHandler(RequestHandlerFactory* factory, Room room, LoggedUser user);

	

protected:
	RequestResult getRoomState(RequestInfo info);
	virtual bool isAdmin() = 0 ;// if Admin - true, if Member - false
	virtual RequestResult logout(RequestInfo info) = 0;
	
	Room _connectedRoom;
	LoggedUser _connectedUser;
	
};