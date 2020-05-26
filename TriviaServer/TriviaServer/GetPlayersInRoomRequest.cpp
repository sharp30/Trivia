#include "GetPlayersInRoomRequest.h"

/*
ctor of this class- cast json to object
*/
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
