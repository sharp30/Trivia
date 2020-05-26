#include "GetRoomsResponse.h"


GetRoomsResponse::GetRoomsResponse(int _status)
{
	this->status = _status;
	this->messageCode = 43;
}

/*
The function will cast a signup response to JSON format
input: none
output: json format of this object
*/
json GetRoomsResponse::castToJson() const
{
	return json{ {"status", this->status} };
}
