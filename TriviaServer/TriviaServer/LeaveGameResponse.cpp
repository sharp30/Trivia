#include "LeaveGameResponse.h"

LeaveGameResponse::LeaveGameResponse(int status)
{
	this->messageCode = 87;
	this->_status = status;
}

nlohmann::json LeaveGameResponse::castToJson() const
{
	return nlohmann::json{ {"status" , _status} };
}
