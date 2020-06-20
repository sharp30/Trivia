#include "Room.h"

//-------constructor-----------
Room::Room(int roomId, LoggedUser creator, string name, int maxPlayers, int questionTime, int questionAmount)
{
	this->_id = roomId;
	this->_users.push_back(creator);

	//other variables:
	this->_questionAmount = questionAmount;
	this->_questionTime = questionTime;
	this->_maxPlayers = maxPlayers;//default-value
	this->_name = name;
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
		throw std::exception(("User: " + userToAdd.getUsername() + " already in room" + std::to_string(this->_id)).c_str());

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

//returns vector of string of all the users in the room
//for example:[ofir, omri, david, moshe]
vector<string> Room::getAllUsers()
{
	vector<string> all;
	for (int i = 0; i < this->_users.size(); i++)
	{
		all.push_back(this->_users[i].getUsername());
	}
	return all;
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
