#include "Game.h"
//------------constructor-------------
Game::Game(int roomId,vector<Question> questions, vector<LoggedUser> players)
{
	this->_roomId = roomId;
	this->m_questions = questions;
	for(LoggedUser user : players)
	{
		this->m_players.insert({ user,GameData() });
	}
}
/*
This function returns a question for a specific user
Input:The requested user
Output:The question for the user
*/
Question Game::getQuestionForUser(LoggedUser user) const
{
	//is finished yet??	
	int place = this->m_players.at(user).currentQuestion;

	if (place >= this->m_questions.size())
		return Question();

	return this->m_questions[this->m_players.at(user).currentQuestion];
}
/*
This function submits the answer of the user and checks it
Input:The requested user, the answer of the user
Output:None
*/
void Game::submitAnswer(LoggedUser user,int answerId)
{
	//check if user exists

	if (!answerId)// correct
		this->m_players[user].correctAnswerCount++;
	else // false
		this->m_players[user].incorrectAnswerCount++;
	
	//next question please!
	this->m_players[user].currentQuestion++;

}
/*
This function removes a player from the game (because of his behavior - yelling, curses and more)
Input:The requested user
Output:None
*/
void Game::removePlayer(LoggedUser user) throw()
{
	//if user exists
	this->m_players.erase(user);
}

int Game::getRoomId()
{
	return this->_roomId;
}

map<LoggedUser, GameData> Game::getPlayersData()
{
	return this->m_players;
}
