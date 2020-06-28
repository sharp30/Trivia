#pragma once

#include "json.hpp"

class CloseRoomRequest
{
public:
	CloseRoomRequest(nlohmann::json j);
	int getRoomId() const;

protected:

	int _roomId;
};