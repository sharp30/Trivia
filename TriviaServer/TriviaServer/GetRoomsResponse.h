#pragma once

#include "Response.h"
#include "Room.h"
#include <vector>

using std::vector;

class GetRoomsResponse : Response
{
public:
	GetRoomsResponse(int _status);
	virtual json castToJson() const;

protected:
	unsigned int status;
	vector<Room> rooms;
};