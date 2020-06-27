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
	GetRoomStateResponse(Room room);
	GetRoomStateResponse(int status, bool gameBegun, vector<string> _players, unsigned int questionsAmount, unsigned int timeToAnswer);
	virtual json castToJson() const;
	string castPlayersToString() const;

protected:
	unsigned int _status;
	bool hasGameBegun;
	vector<string> players;
	unsigned int questionCount;
	unsigned int answerTimeOut;
};