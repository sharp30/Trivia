#pragma once

#include "Response.h"
#include <vector>

using std::vector;

class GetQuestionResponse : Response
{
public:
	GetQuestionResponse(int status, string question, vector<string> answers);
	virtual nlohmann::json castToJson() const;

protected:
	int _status;
	string _question;
	vector<string> _answers;
};