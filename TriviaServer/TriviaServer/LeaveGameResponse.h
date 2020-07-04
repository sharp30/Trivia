#pragma once

#include "Response.h"

class LeaveGameResponse : Response
{
public:
	LeaveGameResponse(int status);
	virtual nlohmann::json castToJson() const;

protected:
	int _status;
};