#pragma once

#include "LoggedUser.h"
#include "Room.h"

#include <map>
#include <set>

using std::map;
using std::set;

class RoomManager
{
public:

	RoomManager();

	void createRoom(LoggedUser creator,string name,int userAmount,int questionTime, int questionAmount) throw();
	void deleteRoom(int roomId) throw();
	bool getRoomState(int roomId) throw();
	bool doesRoomExist(int roomId);
	void addPlayerToRoom(int roomId,string user);
	vector<string> getPlayersInRoom(int roomId);
	vector<Room> getRooms();


protected:
	int findNextRoomId();
	map<int, Room> _rooms;
private:

	set<int> _freeId;
};
