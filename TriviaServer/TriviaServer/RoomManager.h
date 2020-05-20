#pragma once

#include "LoggedUser.h"
#include "Room.h"
#include "Range.h"

#include <map>
#include <set>

using std::map;
using std::set;

class RoomManager
{
public:

	RoomManager() = default;

	void createRoom(LoggedUser creator) throw();
	void deleteRoom(int roomId) throw();
	bool getRoomState(int roomId) throw();
	bool doesRoomExist(int roomId);

	vector<Room> getRooms();

protected:
	int findNextRoomId();
	map<int, Room> _rooms;
private:

	set<int> _freeId;
};
