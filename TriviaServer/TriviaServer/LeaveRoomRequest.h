#pragma once

#include "json.hpp"
class LeaveRoomRequest
{
public:

	LeaveRoomRequest(nlohmann::json j);
	int getRoomId();

protected:
	int _roomId;
};