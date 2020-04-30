#pragma once

#include "Message.h"

class SignupResponse : Message
{
public:
	virtual json castToJson() const;

protected:
	unsigned int status;
};