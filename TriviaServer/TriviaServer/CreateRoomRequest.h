#pragma once

#include <string>
#include "json.hpp"

using std::string;

class CreateRoomRequest
{
public:
	CreateRoomRequest(nlohmann::json j);
	string getRoomName();
	//string getCreatorName();
	unsigned int getMaxUsers();
	unsigned int getQuestionCount();
	unsigned int getAnswerTimeOut();

protected:
	//string creatorName;
	string roomName;
	unsigned int maxUsers;
	unsigned int questionCount;
	unsigned int answerTimeOut;
};
