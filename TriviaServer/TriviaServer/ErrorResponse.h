#pragma once
#include "Response.h"

class ErrorResponse : Response
{
public:
	static const int MSG_CODE = 99;
	ErrorResponse(string errMessage);
	virtual json castToJson() const;

protected:
	string errorMessage;
};