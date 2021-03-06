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

	int createRoom(LoggedUser creator,string name,int userAmount,int questionTime, int questionAmount) throw();
	void deleteRoom(int roomId) throw();
	RoomState getRoomState(int roomId) throw();
	void setRoomState(int roomId, RoomState state);
	bool doesRoomExist(int roomId);
	void addPlayerToRoom(int roomId,string user);
	void RemovePlayerFromRoom(int roomId, string user);
	vector<string> getPlayersInRoom(int roomId);
	vector<Room> getRooms();
	Room getRoom(unsigned int roomID);


	void eraseRoom(int roomId);
protected:
	int findNextRoomId();
	map<int, Room> _rooms;
private:

	set<int> _freeId;
};
