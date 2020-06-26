#pragma once

#include <string>
#include "json.hpp"


using std::string;

class GetRoomStateRequest
{
public:
	GetRoomStateRequest(nlohmann::json j);
	unsigned int getRoomId();

protected:
	unsigned int roomId;
};