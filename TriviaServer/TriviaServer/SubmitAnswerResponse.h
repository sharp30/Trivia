#pragma once

#include "Response.h"

class SubmitAnswerResponse : Response
{
public:
	SubmitAnswerResponse(int status);
	virtual nlohmann::json castToJson() const;

protected:
	int _status;
	unsigned int _correctAnswerId;
};