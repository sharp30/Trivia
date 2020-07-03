#pragma once


#include "json.hpp"

class StartGameRequest
{
public:
	StartGameRequest(nlohmann::json j);
	int getRoomId() const;
protected:
	int _roomId;
};