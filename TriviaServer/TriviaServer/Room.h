#pragma once

#include "LoggedUser.h"

#include <string>
#include <vector>

using std::vector;
using std::string;

class Room
{
public:
	Room() = default;

	Room(int roomId, LoggedUser creator, string name, int maxPlayers, int questionTime, int questionAmount);

	void addUser(LoggedUser userToAdd) throw();
	void removeUser(LoggedUser userToRemove) throw();
	bool isUserExist(LoggedUser userToSearch);
	bool isActive();
	vector<string> getAllUsers();
	string getName() const;

protected:
	vector<LoggedUser> _users;
	//room's data
	int _questionAmount;
	int _id;
	string _name;
	unsigned int _maxPlayers;
	unsigned int _questionTime;
	bool _isActive; // maybe will be enum in the future.

};