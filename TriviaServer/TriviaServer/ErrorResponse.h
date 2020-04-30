#pragma once
#include "Message.h"

class ErrorResponse : Message
{
public:
	ErrorResponse(string errMessage);
	virtual json castToJson() const;

protected:
	string errorMessage;
};