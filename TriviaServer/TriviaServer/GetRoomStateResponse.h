#pragma once

#include "Response.h"
#include "Room.h"
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

class GetRoomStateResponse : Response
{
public:
	GetRoomStateResponse(int status, vector<Room> rooms);
	virtual json castToJson() const;

protected:
	unsigned int _status;
	bool hasGameBegun;
	vector<string> players;
	unsigned int questionCount;
	float answerTimeOut;
};
