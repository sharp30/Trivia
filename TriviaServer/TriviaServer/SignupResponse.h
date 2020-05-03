#pragma once

#include "Response.h"

class SignupResponse : Response
{
public:
	SignupResponse(int _status);
	virtual json castToJson() const;

protected:
	unsigned int status;
};