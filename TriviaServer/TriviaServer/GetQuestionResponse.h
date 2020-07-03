#pragma once


#include "Response.h"
#include <map>

using std::map;

class GetQuestionResponse : Response
{
public:
	GetQuestionResponse(int status, string question, map<unsigned int, string> answers);
	virtual nlohmann::json castToJson() const;

protected:
	int _status;
	string _question;
	map<unsigned int, string> _answers;
};