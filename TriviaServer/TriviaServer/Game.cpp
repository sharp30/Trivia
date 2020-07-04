#include "Game.h"
//------------constructor-------------
Game::Game(vector<Question> questions, vector<LoggedUser> players)
{
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
	//is user exists
	return this->m_questions[this->m_players[user]];
}
/*
This function submits the answer of the user and checks it
Input:The requested user, the answer of the user
Output:None
*/
void Game::submitAnswer(LoggedUser user,string answer)
{
	//check if user exists

	if (this->m_questions[this->m_players[user].currentQuestion].getCorrectAnswer() == answer)// correct
		this->m_players[user].correctAnswerCount++;
	else // false
		this->m_players[user].incorrectAnswerCount++;
	
	//next question please!
	this->m_players[user].incorrectAnswerCount--;

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
