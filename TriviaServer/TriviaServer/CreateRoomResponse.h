#pragma once

#include "Response.h"

class CreateRoomResponse : Response
{
public:
	CreateRoomResponse(int _status);
	virtual json castToJson() const;

protected:
	unsigned int status;
};