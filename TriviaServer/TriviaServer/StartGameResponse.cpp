#include "StartGameResponse.h"

StartGameResponse::StartGameResponse(int status)
{
	this->_status = status;
	this->messageCode = 53;
}

nlohmann::json StartGameResponse::castToJson() const
{
	return nlohmann::json{ {"status" , _status} };
}