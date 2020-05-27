#pragma once

#include "Response.h"
#include <vector>

using std::vector;

class GetPlayersInRoomResponse : Response
{
public:
	GetPlayersInRoomResponse();
	virtual json castToJson() const;
	string castPlayersToString() const;

protected:
	vector<string> players;

};