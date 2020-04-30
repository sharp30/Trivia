#pragma once

#include "Message.h"

class LoginResponse : Message
{
public:
	LoginResponse(int _status);
	virtual json castToJson() const;

protected:
	unsigned int status;
};