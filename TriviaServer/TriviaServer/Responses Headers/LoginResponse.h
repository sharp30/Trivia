#pragma once

#include "Response.h"
#include <vector>
class LoginResponse : Response
{
public:
	LoginResponse(int _status);
	virtual json castToJson() const;
protected:

	unsigned int status;
};