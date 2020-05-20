#pragma once

#include <string>
#include "json.hpp"


using std::string;

class JoinRoomRequest
{
public:
	JoinRoomRequest(nlohmann::json j);
	unsigned int getRoomId();

protected:
	unsigned int roomId;
};
