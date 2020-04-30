#pragma once
#include "Message.h"

class ErrorResponse : Message
{
public:
	virtual json castToJson() const;

protected:
	string errorMessage;
};