#include "GetRoomStateResponse.h"

GetRoomStateResponse::GetRoomStateResponse(Room room)
{
	this->messageCode = 49;

	this->_status = 1;
	this->state =(int)room.getState();
	this->players = room.getAllUsers();
	this->questionCount = room.getQuestionAmount();
	this->answerTimeOut = room.getQuestionTime();
}

GetRoomStateResponse::GetRoomStateResponse(int status, RoomState _state, vector<string> _players, unsigned int questionsAmount, unsigned int timeToAnswer)
{
	this->messageCode = 49;

	this->_status = status;
	this->state = (int)_state;
	this->players = _players;
	this->questionCount = questionsAmount;
	this->answerTimeOut = timeToAnswer;
}

json GetRoomStateResponse::castToJson() const
{
	return json{ {"status", this->_status}, {"state", this->state}, {"players", castPlayersToString() },
		{"questionCount", this->questionCount}, {"answerTimeOut", this->answerTimeOut} };
}

string GetRoomStateResponse::castPlayersToString() const
{
	string txt = "";

	for (int i = 0; i < this->players.size(); i++)
	{
		txt += this->players[i] + ",";
	}

	return txt.substr(0, txt.size() - 1);
}