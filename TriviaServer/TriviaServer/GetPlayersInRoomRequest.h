#pragma once

#include <string>
#include "json.hpp"


using std::string;

class GetPlayersInRoomRequest
{
public:
	GetPlayersInRoomRequest(nlohmann::json j);
	unsigned int getRoomId();

protected:
	unsigned int roomId;
};
