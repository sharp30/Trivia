#include "JoinRoomRequest.h"

/*
ctor of this class- cast json to object
*/
JoinRoomRequest::JoinRoomRequest(nlohmann::json j)
{
	this->roomId = j.at("roomId").get<unsigned int>();
}


/*
This function returns the room id
Input:None
Output: The room id
*/
unsigned int JoinRoomRequest::getRoomId()
{
	return this->roomId;
}
