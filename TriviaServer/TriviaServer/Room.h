#pragma once

#include "LoggedUser.h"

#include <string>
#include <vector>

using std::vector;
using std::string;




typedef enum RoomStates {
	CLOSED = -1, WAITNG, ACTIVE
} RoomState;

class Room
{
public:
	Room() = default;
	Room(int roomId, LoggedUser creator,string name,int maxPlayers,int questionTime,int questionAmount);//for now

	void addUser(LoggedUser userToAdd) throw();
	void removeUser(LoggedUser userToRemove) throw();
	bool isUserExist(LoggedUser userToSearch);
	RoomState getState();
	void setState(RoomState state);
	vector<string> getAllUsers();
	string getName() const;
	int getID() const;
	unsigned int getQuestionAmount() const;
	unsigned int getMaxPlayersAmount() const;
	unsigned int getQuestionTime() const;

protected:
	vector<LoggedUser> _users;

	//room's data
	int _id;
	string _name;
	unsigned int _questionAmount;
	unsigned int _maxPlayers;
	unsigned int _questionTime;
	RoomState _state; 

};