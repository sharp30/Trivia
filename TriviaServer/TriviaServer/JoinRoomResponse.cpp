#include "JoinRoomResponse.h"


JoinRoomResponse::JoinRoomResponse(int _status)
{
	this->status = _status;
	this->messageCode = 45;
}

/*
The function will cast a join room response to JSON format
input: none
output: json format of this object
*/
json JoinRoomResponse::castToJson() const
{
	return json{ {"status", this->status} };
}
