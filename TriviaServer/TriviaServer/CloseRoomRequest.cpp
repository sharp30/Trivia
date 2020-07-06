#include "CloseRoomRequest.h"

//-------------constructor---------------
CloseRoomRequest::CloseRoomRequest(nlohmann::json j)
{
	this->_roomId = j.at("roomId").get<int>();

}

int CloseRoomRequest::getRoomId() const
{
	return _roomId;
}
