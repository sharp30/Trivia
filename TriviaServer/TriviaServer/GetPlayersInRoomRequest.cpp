#include "GetPlayersInRoomRequest.h"

GetPlayersInRoomRequest::GetPlayersInRoomRequest(nlohmann::json j)
{
	this->roomId = j.at("roomId").get<unsigned int>();
}


/*
This function returns the room id
Input:None
Output: The room id
*/
unsigned int GetPlayersInRoomRequest::getRoomId()
{
	return this->roomId;
}
