#include "GameManager.h"

GameManager::GameManager(IDatabase* database)
{
	this->_database = database;
}

//returns the id of the new Game
int GameManager::createGame(Room room)
{
	//TODO: change state of room - > at RoomManager maybe?

	int id = this->_database->createGame();
	vector<Question> q = this->_database->buildQuestions(room.getQuestionAmount());

	this->_games.insert({ id,Game(room.getID(),q,room.getAllLoggedUsers()) });
	return id;
}
void GameManager::deleteGame(int gameId) throw()
{
	if (this->_games.find(gameId) == this->_games.begin())
		throw std::exception(("Game " + std::to_string(gameId) + " Isn't exist").c_str());
	
	this->_games.erase(gameId);
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

Question GameManager::getQuestionForUser(int gameId, LoggedUser user)
{
	return this->_games[gameId].getQuestionForUser(user);
}

void GameManager::submitAnswer(int gameId, LoggedUser user, int answerid)
{
	Question current = getQuestionForUser(gameId, user);
	this->_games[gameId].submitAnswer(user, answerid);
	
	this->_database.submitUserAnswer(gameId,user.getUsername(),current.getQuestion(),current.getPossibleAnswers()[answerid],!answerid,"time");
}

void GameManager::removePlayer(int gameId, LoggedUser user) throw()
{
	this->_games[gameId].removePlayer(user);
}
