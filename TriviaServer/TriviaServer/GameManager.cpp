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

	this->_games.insert({ id,Game(q,room.getAllLoggedUsers()) });
}
