#include "Room.h"

//-------constructor-----------
Room::Room(int roomId, LoggedUser creator)
{
	this->_id = roomId;
	this->_users.push_back(creator);
	
	//other variables:
	this->_isActive = false;
	this->_maxPlayers = 2;//default-value
	this->_name = "Avram";
}
/*
This function adds user from a room
Input : userToAdd: the user : LoggedUser
Output : None
Throw : The function will throw exception if the is in the room
*/
void Room::addUser(LoggedUser userToAdd) throw()
{
	if (this->isUserExist(userToAdd))
		throw std::exception(("User: " + userToAdd.getUsername() + " already in the room").c_str());

	this->_users.push_back(userToAdd);

}
/*
This function removes user from a room
Input : userToRemove: the user : LoggedUser
Output:None
Throw: The function will throw exception if the isn't in the room
*/
void Room::removeUser(LoggedUser userToRemove) throw()
{
	if (!this->isUserExist(userToRemove))
		throw std::exception(("User: " + userToRemove.getUsername() + " isn't in the room").c_str());

	this->_users.erase(std::find(this->_users.begin(), this->_users.end(), userToRemove)); //remove from vector
}

/*
This function checks if a user is in the room
Input: userToSearch: the user : LoggedUser
Output:Boolean value - is the user in the room?
*/
bool Room::isUserExist(LoggedUser userToSearch)
{
	return std::find(this->_users.begin(), this->_users.end(), userToSearch) != this->_users.end();
}

//returns string of all the users in the room
//for example:ofir, omri, david, moshe
string Room::getAllUsers()
{
	string users = "";
	for (size_t i = 0; i < this->_users.size();i++)
	{
		users += this->_users[i].getUsername() + ", ";
	}
	if (users.size() > 2)
		users.substr(0, users.size() - 2);
	return users;

}

string Room::getName() const
{
	return this->_name;
}

//getters
bool Room::isActive()
{
	return this->_isActive;
}
