#pragma once

#include "Response.h"

class GetStatisticsResponse : Response
{
public:
	GetStatisticsResponse(int _status);
	virtual json castToJson() const;
protected:

	unsigned int status;
};