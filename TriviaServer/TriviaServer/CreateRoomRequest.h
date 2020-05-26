#pragma once

#include <string>
#include "json.hpp"


using std::string;

class CreateRoomRequest
{
public:
	CreateRoomRequest(nlohmann::json j);
	string getRoomName();
	unsigned int getMaxUsers();
	unsigned int getQuestionCount();
	unsigned int getAnswerTimeOut();

protected:
	string roomName;
	unsigned int maxUsers;
	unsigned int questionCount;
	unsigned int answerTimeOut;
};
