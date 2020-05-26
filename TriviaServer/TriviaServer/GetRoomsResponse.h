#pragma once

#include "Response.h"

class GetRoomsResponse : Response
{
public:
	GetRoomsResponse(int _status);
	virtual json castToJson() const;

protected:
	unsigned int status;
};