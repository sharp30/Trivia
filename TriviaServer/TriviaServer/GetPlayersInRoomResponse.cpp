#include "GetPlayersInRoomResponse.h"




GetPlayersInRoomResponse::GetPlayersInRoomResponse(string players)
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
	this->_players;
}