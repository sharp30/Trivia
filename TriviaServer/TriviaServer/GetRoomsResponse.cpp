#include "GetRoomsResponse.h"


GetRoomsResponse::GetRoomsResponse(int status,vector<Room> rooms)
{
	this->_rooms = rooms;
	this->_status = status;
	this->messageCode = 43;
}

/*
The function will cast a signup response to JSON format
input: none
output: json format of this object
*/
json GetRoomsResponse::castToJson() const
{
	//string roomsStr = castRoomsToString();
	return json{ {"status", this->_status}, {"rooms", castRoomsToString()} };
}

/*
The function will return the IDs of All the rooms in the following format:
 "ID1,ID2,ID3,ID4"
input: none
output: string contains the IDs of the rooms
*/
string GetRoomsResponse::castRoomsToString() const
{
	string str = "";

	vector<Room> temp = this->_rooms;

	for (vector<Room>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		str += std::to_string(it->getID());
		str += ":";
		str += it->getName();
		str += ",";
	}

	return str.substr(0, str.length() - 1);
}