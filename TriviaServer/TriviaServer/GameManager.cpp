#include "GameManager.h"

GameManager::GameManager(IDatabase* database)
{
	this->_database = database;
}

void GameManager::createGame(Room room)
{
	//TODO: change state of room - > at RoomManager maybe?

	int id = this->_database->createGame();
	vector<Question> q = this->_database->buildQuestions(room.getQuestionAmount());

	this->_games.insert({ id,Game(room.getID(),q,room.getAllLoggedUsers()) });
}
/*
This function returns the id of a game by a roomId
Input:a room Id
Output:The id of the game // IF NOT FOUND - 1
*/
int GameManager::getGameIdByRoomID(int roomId)
{
	map<int, Game>::iterator it=this->_games.begin();
	for (it;it!= this->_games.end();it++)
	{
		if (it->second.getRoomId() == roomId)
			return it->first;
	}
	return -1;//NOT FOUND
}
