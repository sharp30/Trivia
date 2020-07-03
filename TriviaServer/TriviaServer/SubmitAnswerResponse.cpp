#include "SubmitAnswerResponse.h"

SubmitAnswerResponse::SubmitAnswerResponse(int status, unsigned int correctAnswerId)
{
	this->messageCode = 82;
	this->_status = status;
	this->_correctAnswerId = correctAnswerId;
}

nlohmann::json SubmitAnswerResponse::castToJson() const
{
	return nlohmann::json{ {"status" , _status}, {"correctAnswerId", this->_correctAnswerId} };
}
