#pragma once

#include "Response.h"
#include "Room.h"
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

class GetRoomsResponse : Response
{
public:
	GetRoomsResponse(int _status);
	virtual json castToJson() const;
	string castRoomsToString() const;

protected:
	unsigned int status;
	vector<Room> rooms;
};