#include "GetPlayersInRoomResponse.h"


GetPlayersInRoomResponse::GetPlayersInRoomResponse(int _status)
{
	this->status = _status;
	this->messageCode = 47;
}

/*
The function will cast a signup response to JSON format
input: none
output: json format of this object
*/
json GetPlayersInRoomResponse::castToJson() const
{
	return json{ {"status", this->status} };
}
