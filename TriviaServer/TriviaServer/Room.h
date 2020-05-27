#pragma once

#include "LoggedUser.h"

#include <string>
#include <vector>

using std::vector;
using std::string;

class Room
{
public:

	Room(int roomId, LoggedUser creator);//for now

	void addUser(LoggedUser userToAdd) throw();
	void removeUser(LoggedUser userToRemove) throw();
	bool isUserExist(LoggedUser userToSearch);
	bool isActive();
	void getAllUsers();//need to think on return type
	string getName() const;

protected:
	vector<LoggedUser> _users;
	//room's data
	int _id;
	string _name;
	unsigned int _maxPlayers;
	unsigned int _questionTime;
	bool _isActive; // maybe will be enum in the future.

};