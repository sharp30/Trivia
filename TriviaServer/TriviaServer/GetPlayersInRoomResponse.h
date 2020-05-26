#pragma once

#include "Response.h"
#include <vector>

using std::vector;

class GetPlayersInRoomResponse : Response
{
public:
	GetPlayersInRoomResponse(int _status);
	virtual json castToJson() const;
protected:
	vector<string> players;

};