#pragma once
#include "Response.h"

class ErrorResponse : Response
{
public:
	ErrorResponse(string errMessage);
	virtual json castToJson() const;

protected:
	string errorMessage;
};