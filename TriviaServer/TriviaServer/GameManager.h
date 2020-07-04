#pragma once
#pragma once

#include "IDatabase.h"
#include "Game.h"
#include "Room.h"

class GameManager
{
public:
	GameManager(IDatabase* database);
	void createGame(Room room);
	void deleteGame() throw();
	int getGameIdByRoomID(int roomId);

	//getGame by id
protected:

	IDatabase* _database;
	map<int,Game> _games;//{game_id,game}
};