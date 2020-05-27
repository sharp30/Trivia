#pragma once

#include "Response.h"
#include <vector>

using std::vector;

class GetStatisticsResponse : Response
{
public:
	GetStatisticsResponse(int _status);
	virtual json castToJson() const;
	string castStatisticsToString() const;

protected:
	vector<string> statistics;
	unsigned int status;

};