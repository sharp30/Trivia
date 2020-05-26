#include "GetStatisticsResponse.h"


GetStatisticsResponse::GetStatisticsResponse(int _status)
{
	this->status = _status;
	this->messageCode = 71;
}

/*
The function will cast a signup response to JSON format
input: none
output: json format of this object
*/
json GetStatisticsResponse::castToJson() const
{
	return json{ {"status", this->status} };
}
