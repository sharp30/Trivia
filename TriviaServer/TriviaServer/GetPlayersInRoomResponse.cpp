#include "GetPlayersInRoomResponse.h"


GetPlayersInRoomResponse::GetPlayersInRoomResponse()
{
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
	string str = "";

	vector<string> temp = this->players;

	for (vector<string>::iterator it = temp.begin(); it != temp.end(); ++it)
	{
		str += *it;
		str += ", ";
	}

	return str.substr(0, str.length() - 2);
}