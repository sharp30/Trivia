#pragma once

#include "Response.h"

class LogoutResponse : Response
{
public:
	LogoutResponse(int _status);
	virtual json castToJson() const;
protected:

	unsigned int status;
};