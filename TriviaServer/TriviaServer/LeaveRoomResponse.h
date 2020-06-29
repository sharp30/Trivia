#pragma once

#include "Response.h"

class LeaveRoomResponse : public Response
{
public:
	LeaveRoomResponse(int status);
	virtual nlohmann::json castToJson() const;

protected:
	int _status;
};