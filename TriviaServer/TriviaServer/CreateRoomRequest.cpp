#include "CreateRoomRequest.h"

/*
ctor of this class- cast json to object
*/
CreateRoomRequest::CreateRoomRequest(nlohmann::json j)
{
	this->roomName = j.at("roomName").get<string>();
	this->maxUsers = j.at("maxUsers").get<unsigned int>();
	this->questionCount = j.at("questionCount").get<unsigned int>();
	this->answerTimeOut = j.at("answerTimeOut").get<unsigned int>();
}

/*
This function returns the room name
Input: None
Output: The room name
*/
string CreateRoomRequest::getRoomName()
{
	return this->roomName;
}

/*
This function returns the max amount of users in the room
Input: None
Output: amount of users in room
*/
unsigned int CreateRoomRequest::getMaxUsers()
{
	return this->maxUsers;
}

/*
This function returns amount of questions in the room
Input: None
Output: amount of questions in the room
*/
unsigned int CreateRoomRequest::getQuestionCount()
{
	return this->questionCount;
}

/*
This function returns the answer timeout
Input: None
Output: the answer timeout
*/
unsigned int CreateRoomRequest::getAnswerTimeOut()
{
	return this->answerTimeOut;
}
