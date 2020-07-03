#pragma once

#include "Response.h"
#include <map>

using std::map;

class SubmitAnswerResponse : Response
{
public:
	SubmitAnswerResponse(int status, unsigned int correctAnswerId);
	virtual nlohmann::json castToJson() const;

protected:
	int _status;
	unsigned int _correctAnswerId;
};