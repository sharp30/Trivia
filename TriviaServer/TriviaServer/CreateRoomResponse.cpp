#include "CreateRoomResponse.h"


CreateRoomResponse::CreateRoomResponse(int _status)
{
	this->status = _status;
	this->messageCode = 41;
}

/*
The function will cast a signup response to JSON format
input: none
output: json format of this object
*/
json CreateRoomResponse::castToJson() const
{
	return json{ {"status", this->status} };
}
