#include "RoomManager.h"
#include <cstdlib>
//----------------constructor------------
RoomManager::RoomManager()
{
	this->_freeId.insert(0); //first value
}

/*
This function creates a new room 
Input: creator - the creator of the room :LoggedUser
Output:None
*/
void RoomManager::createRoom(LoggedUser creator) 
{
	int id = this->findNextRoomId();
	this->_rooms.insert(std::pair<int, Room>(id, Room(id, creator)));
}

/*
This function deletes a room
Input: roomId - the id of the room : int
Output: None
Throw: If the room doesn't exist
*/
void RoomManager::deleteRoom(int roomId) throw()
{
	if (!this->doesRoomExist(roomId))
		throw std::exception(("Room " + std::to_string(roomId) + "doesn't exist").c_str());
	this->_rooms.erase(this->_rooms.find(roomId));
	this->_freeId.insert(roomId);
}

/*
This function returns the state of a room in a requested id
Input: roomId - the id of the room : int
Output:The state of the room : bool
Throw: If the room doesn't exist
*/
bool RoomManager::getRoomState(int roomId) throw()
{
	if (!this->doesRoomExist(roomId))
		throw std::exception(("Room " + std::to_string(roomId) + "doesn't exist").c_str());
	return this->_rooms.at(roomId).isActive();
}
/*
This function checks if a room already exists
Input:roomId - the id of the room : int
Output:does the room exist : bool
*/
bool RoomManager::doesRoomExist(int roomId)
{
	return this->_rooms.find(roomId) != this->_rooms.end();
}
/*
This function returns string of all the users in the room
Input: roomId - the id of the room
Output: string of all the users in the room
Throw: If the room doesn't exist
*/
string RoomManager::getPlayersInRoom(int roomId) throw()
{
	if (!this->doesRoomExist(roomId))
		throw std::exception(("Room " + std::to_string(roomId) + "doesn't exist").c_str());
	return this->_rooms.at(roomId).getAllUsers();
}
/*
This function returns vector of all the existing rooms
Input:None
Output: vector of all the rooms
*/
vector<Room> RoomManager::getRooms()
{
	std::vector<Room> all;
	map<int, Room>::iterator it = this->_rooms.begin();
	
	for (; it != this->_rooms.end(); it++)
	{
		all.push_back(it->second);
	}

	return all;
}
/*
This function returns the id for the room (the smallest one)
Input:None
Output:The id for the room
*/
int RoomManager::findNextRoomId()
{
	int place = *(this->_freeId.begin());
	this->_freeId.erase(this->_freeId.begin()); //delete value

	if (this->_freeId.empty()) // if it was taken from end
		this->_freeId.insert(place + 1);

	return place;
}
