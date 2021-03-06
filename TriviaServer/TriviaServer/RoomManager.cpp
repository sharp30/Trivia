#include "RoomManager.h"
#include <cstdlib>
#include <thread>

//----------------constructor------------
RoomManager::RoomManager()
{
	this->_freeId.insert(0); //first value
}

/*
This function creates a new room 
Input: creator - the creator of the room :LoggedUser
Output:The id of the new room
*/
int RoomManager::createRoom(LoggedUser creator, string name, int userAmount, int questionTime, int questionAmount) throw()
{
	int id = this->findNextRoomId();
	this->_rooms.insert(std::pair<int, Room>(id, Room(id, creator,name,userAmount,questionTime,questionAmount)));
	return id;
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
RoomState RoomManager::getRoomState(int roomId) throw()
{
	if (!this->doesRoomExist(roomId))
		throw std::exception(("Room " + std::to_string(roomId) + "doesn't exist").c_str());
	return this->_rooms.at(roomId).getState();
}
void RoomManager::setRoomState(int roomId, RoomState state)
{
	if(!doesRoomExist(roomId))
		throw std::exception(("Room " + std::to_string(roomId) + "doesn't exist").c_str());
	this->_rooms[roomId].setState(state);
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
void RoomManager::addPlayerToRoom(int roomId, string user)
{
	if(!this->doesRoomExist(roomId))
		throw std::exception(("Room " + std::to_string(roomId) + "doesn't exist").c_str());
	this->_rooms[roomId].addUser(user);
}
void RoomManager::RemovePlayerFromRoom(int roomId, string user)
{
	if (!this->doesRoomExist(roomId))
		throw std::exception(("Room " + std::to_string(roomId) + "doesn't exist").c_str());
	this->_rooms[roomId].removeUser(user);
}
/*
This function returns string of all the users in the room
Input: roomId - the id of the room
Output: string of all the users in the room
Throw: If the room doesn't exist
*/
vector<string> RoomManager::getPlayersInRoom(int roomId) throw()
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
Room RoomManager::getRoom(unsigned int roomID) throw()
{
	if (doesRoomExist(roomID))
		return this->_rooms.at(roomID);
	throw std::exception("Room doesn't exist");
}
void RoomManager::eraseRoom(int roomId)
{
	std::this_thread::sleep_for(std::chrono::seconds(5));
	try
	{
		this->deleteRoom(roomId);
	}
	catch (std::exception e)
	{

	}
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