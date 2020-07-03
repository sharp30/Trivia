#include "GetQuestionResponse.h"

GetQuestionResponse::GetQuestionResponse(int status, string question, map<unsigned int, string> answers)
{
	this->messageCode = 81;
	this->_status = status;
	this->_question = question;
	this->_answers = answers;
}

nlohmann::json GetQuestionResponse::castToJson() const
{
	return nlohmann::json{ {"status" , _status}, {"question", this->_question}, {"answers", this->_answers} };
}
