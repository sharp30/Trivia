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
	return nlohmann::json{ {"status" , _status}, {"question", this->_question}, {"answers", castAnswersToString()} };
}


string GetQuestionResponse::castAnswersToString() const
{
	string str = "";

	vector<string> temp = this->_answers;

	for (vector<string>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		str += *it;
		str += "*";
	}

	return str.substr(0, str.length() - 1);
}


