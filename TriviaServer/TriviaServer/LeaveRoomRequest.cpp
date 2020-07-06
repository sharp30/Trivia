#include "LeaveRoomRequest.h"
// -------------constructor-------------
LeaveRoomRequest::LeaveRoomRequest(nlohmann::json j)
{
	this->_roomId = j.at("RoomId").get<int>();
}

int LeaveRoomRequest::getRoomId()
{
	return this->_roomId;
}
