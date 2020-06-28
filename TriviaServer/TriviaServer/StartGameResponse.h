#pragma once

#include "Response.h"

class StartGameResponse : Response
{
public:
	StartGameResponse(int status);
	virtual nlohmann::json castToJson();

protected:
	int _status;
};