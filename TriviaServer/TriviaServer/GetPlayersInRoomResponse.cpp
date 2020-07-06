#include "GetPlayersInRoomResponse.h"




GetPlayersInRoomResponse::GetPlayersInRoomResponse(vector<string> players)
{
	this->_players = players;
	this->messageCode = 47;
}

/*
The function will cast a signup response to JSON format
input: none
output: json format of this object
*/
json GetPlayersInRoomResponse::castToJson() const
{
	return json{ {"PlayersInRoom", castPlayersToString()} };
}


string GetPlayersInRoomResponse::castPlayersToString() const
{
	string txt = "";

	for (int i = 0; i < this->_players.size(); i++)
	{
		txt += this->_players[i] + " ,";
	}

	if (this->_players.size() > 2)
		txt = txt.substr(0, txt.size() - 2);
	
	return txt;
}