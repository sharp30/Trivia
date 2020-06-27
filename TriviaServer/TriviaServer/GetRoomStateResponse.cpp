#include "GetRoomStateResponse.h"

GetRoomStateResponse::GetRoomStateResponse(int status, bool gameBegun, vector<string> _players, unsigned int questionsAmount, float timeToAnswer)
{
	this->messageCode = 48;

	this->_status = status;
	this->hasGameBegun = gameBegun;
	this->players = _players;
	this->questionCount = questionsAmount;
	this->answerTimeOut = timeToAnswer;
}

json GetRoomStateResponse::castToJson() const
{
	return json{ {"status", this->_status}, {"hasGameBegun", this->hasGameBegun}, {"players", castPlayersToString() },
		{"answerCount", this->questionCount}, {"answerTimeOut", this->answerTimeOut} };
}

string GetRoomStateResponse::castPlayersToString() const
{
	string txt = "";

	for (int i = 0; i < this->players.size(); i++)
	{
		txt += this->players[i] + " ,";
	}

	if (this->players.size() > 2)
		txt = txt.substr(0, txt.size() - 2);

	return txt;
}