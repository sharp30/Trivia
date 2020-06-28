#include "LeaveRoomResponse.h"

LeaveRoomResponse::LeaveRoomResponse(int status)
{
	this->_status = status;
	this->messageCode = 55;
}

nlohmann::json LeaveRoomResponse::castToJson()
{
	return nlohmann::json{ {"status",_status} };
}
