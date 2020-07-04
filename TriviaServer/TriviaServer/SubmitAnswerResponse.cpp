#include "SubmitAnswerResponse.h"

SubmitAnswerResponse::SubmitAnswerResponse(int status)
{
	this->messageCode = 83;
	this->_status = status;
	this->_correctAnswerId = 0; //ID of correct answer is always 0
}

nlohmann::json SubmitAnswerResponse::castToJson() const
{
	return nlohmann::json{ {"status" , _status}, {"correctAnswerId", this->_correctAnswerId} };
}
