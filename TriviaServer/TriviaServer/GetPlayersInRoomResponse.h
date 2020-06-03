#pragma once

#include "Response.h"
#include <vector>

using std::vector;

class GetPlayersInRoomResponse : Response
{
public:
	GetPlayersInRoomResponse(string players);
	virtual json castToJson() const;
	string castPlayersToString() const;

protected:
	string _players;

};