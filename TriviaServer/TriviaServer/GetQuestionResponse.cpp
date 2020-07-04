#include "GetQuestionResponse.h"

GetQuestionResponse::GetQuestionResponse(int status, string question, vector<string> answers)
{
	this->messageCode = 81;
	this->_status = status;
	this->_question = question;
	this->_answers = answers;
}

nlohmann::json GetQuestionResponse::castToJson() const
{
	//#TODO: check if putting this->_answers directly in json is valid or it should go through conversion to a single string. 
	return nlohmann::json{ {"status" , _status}, {"question", this->_question}, {"answers", this->_answers} };
}
