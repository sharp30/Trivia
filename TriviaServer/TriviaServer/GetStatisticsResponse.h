#pragma once

#include "Response.h"
#include <map>

using std::vector;

class GetStatisticsResponse : Response
{
public:
	GetStatisticsResponse(int _status,std::map<string,string> data);
	virtual json castToJson() const;
//	string castStatisticsToString() const;

protected:
	std::map<string,string> statistics;
	unsigned int status;

};