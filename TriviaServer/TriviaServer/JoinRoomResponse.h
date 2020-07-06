#pragma once

#include "Response.h"

class JoinRoomResponse : Response
{
public:
	JoinRoomResponse(int _status);
	virtual json castToJson() const;
protected:

	unsigned int status;
};