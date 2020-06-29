#include "CloseRoomResponse.h"

CloseRoomResponse::CloseRoomResponse(int status)
{
	this->_status = status;
	this->messageCode = 51;
}

nlohmann::json CloseRoomResponse::castToJson() const
{
	return nlohmann::json{ {"status" , _status} };
}

