#pragma once

#include "Message.h"
#include <vector>
class LoginResponse : Message
{
public:
	LoginResponse(int _status);
	virtual json castToJson() const;
protected:

	unsigned int status;
};