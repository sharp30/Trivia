#pragma once
#pragma once

#include "IDatabase.h"
#include "Game.h"
#include "Room.h"

class GameManager
{
public:
	GameManager(IDatabase* database);
	int createGame(Room room);
	void deleteGame(int gameId) throw();
	int getGameIdByRoomID(int roomId);
	Question getQuestionForUser(int gameId, LoggedUser user);
	void submitAnswer(int gameId, LoggedUser user, int answerId);
	void removePlayer(int gameId, LoggedUser user) throw();
protected:

	IDatabase* _database;
	map<int,Game> _games;//{game_id,game}
};