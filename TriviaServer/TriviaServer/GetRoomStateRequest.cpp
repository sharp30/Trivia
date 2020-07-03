#include "GetRoomStateRequest.h"

/*
ctor of this class- cast json to object
*/
GetRoomStateRequest::GetRoomStateRequest(nlohmann::json j)
{
	this->roomId = j.at("roomId").get<unsigned int>();
}


/*
This function returns the room id
Input:None
Output: The room id
*/
unsigned int GetRoomStateRequest::getRoomId()
{
	return this->roomId;
}
