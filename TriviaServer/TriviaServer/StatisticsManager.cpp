#include "StatisticsManager.h"

//------------constructor------------
StatisticsManager::StatisticsManager(IDatabase* database)
{
	this->m_database = database;
}

map<string,string> StatisticsManager::getStatistics(string username) throw()
{
	std::map<string,string> stats;

	int gamesAmount = 0;
	int correctAnswers = 0;
	int incorrectAnswers = 0;
	float averageAnswerTime = 0;
	int amountOfAnswers = 0;
	gamesAmount = this->m_database->getNumOfPlayerGames(username);
	correctAnswers = this->m_database->getNumOfCorrectAnswers(username);
	amountOfAnswers = this->m_database->getNumOfTotalAnswers(username);
	incorrectAnswers = amountOfAnswers - correctAnswers;
	if(amountOfAnswers > 0)
		averageAnswerTime = this->m_database->getPlayerAverageAnswerTime(username);

	stats.insert({"gamesAmount", std::to_string(gamesAmount) });
	stats.insert({"correctAnswers", std::to_string(correctAnswers) });
	stats.insert({"incorrectAnswers", std::to_string(incorrectAnswers) });
	stats.insert({"averageAnswerTime", std::to_string(averageAnswerTime) });


	return stats;
}

/*
The function will return the names of the 5 best players according to their points in the following format:
			vector: {"playername:points","playername:points","playername:points"}
input: none
output: vector of details as described below
*/
vector<string> StatisticsManager::getBestPlayers() throw()
{
	return this->m_database->getBestPlayers();
}
