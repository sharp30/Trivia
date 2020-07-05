#pragma once
#include "RoomHandler.h"
#include "RequestHandlerFactory.h"


class RoomAdminRequestHandler : RoomHandler
{
public:
	RoomAdminRequestHandler(RequestHandlerFactory* factory, LoggedUser user, Room connectedRoom);
	virtual bool isRequestRelevant(RequestInfo);
	virtual RequestResult handleRequest(RequestInfo);
	virtual RequestResult logout(RequestInfo info);

protected:
	virtual bool isAdmin();


};