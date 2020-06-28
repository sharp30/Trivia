#pragma once


#include "Response.h"

class CloseRoomResponse : Response
{
public:
	CloseRoomResponse(int status);
	virtual nlohmann::json castToJson();

protected:
	int _status;

};