#include "StartGameRequest.h"

//----------constructor----------
StartGameRequest::StartGameRequest(nlohmann::json j)
{
	this->_roomId = j.at("RoomId").get<int>();
}

int StartGameRequest::getRoomId() const
{
	return this->_roomId;
}
