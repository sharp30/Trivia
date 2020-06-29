#pragma once

#include "Response.h"

class StartGameResponse : Response
{
public:
	StartGameResponse(int status);
	virtual json castToJson() const;

protected:
	int _status;
};