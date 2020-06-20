#pragma once

#include "Response.h"
#include <vector>

using std::vector;

class GetStatisticsResponse : Response
{
public:
	GetStatisticsResponse(int _status,vector<string> data);
	virtual json castToJson() const;
	string castStatisticsToString() const;

protected:
	vector<string> statistics;
	unsigned int status;

};