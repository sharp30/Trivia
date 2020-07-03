#include "SubmitAnswerRequest.h"

SubmitAnswerRequest::SubmitAnswerRequest(nlohmann::json j)
{
	this->_answerId = j.at("answerId").get<unsigned int>();
}

unsigned int SubmitAnswerRequest::getAnswerId()
{
	return this->_answerId;
}
