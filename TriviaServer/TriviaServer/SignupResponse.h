#pragma once

#include "Message.h"

class SignupResponse : Message
{
public:
	SignupResponse(int _status);
	virtual json castToJson() const;

protected:
	unsigned int status;
};