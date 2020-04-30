#pragma once

#include "Message.h"

class LoginResponse : Message
{
public:
	virtual json castToJson() const;

protected:
	unsigned int status;
};