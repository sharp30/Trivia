#include "GetRoomsResponse.h"


GetRoomsResponse::GetRoomsResponse(int _status)
{
	this->status = _status;
	this->messageCode = 43;
}

/*
The function will cast a signup response to JSON format
input: none
output: json format of this object
*/
json GetRoomsResponse::castToJson() const
{
	string roomsStr = castRoomsToString();
	return json{ {"status", this->status}, {"Rooms", castRoomsToString()} };
}

string GetRoomsResponse::castRoomsToString() const
{
	string str = "";

	vector<Room> temp;

	std::copy(this->rooms.begin(), this->rooms.end(), temp);

	for (vector<Room>::iterator it = temp.begin(); it != this->rooms.end(); it++)
	{
		str += it->getName();
		str += ", ";
	}

	return str.substr(0, str.length() - 2);
}
