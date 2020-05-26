#pragma once

#include "Response.h"
#include <vector>
class GetPlayersInRoomResponse : Response
{
public:
	GetPlayersInRoomResponse(int _status);
	virtual json castToJson() const;
protected:

	unsigned int status;
};