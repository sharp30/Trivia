#include "StatisticsManager.h"

//------------constructor------------
StatisticsManager::StatisticsManager(IDatabase* database)
{
	this->m_database = database;
}

vector<string> StatisticsManager::getStatistics(string username) throw()
{
	vector<string> stats;

	int gamesAmount = 0;
	int rightAnswers = 0;
	int wrongAnswers = 0;
	float averageAnswerTime = 0;

	gamesAmount = this->m_database->getNumOfPlayerGames(username);
	rightAnswers = this->m_database->getNumOfCorrectAnswers(username);
	wrongAnswers = this->m_database->getNumOfTotalAnswers(username) - rightAnswers;
	averageAnswerTime = this->m_database->getPlayerAverageAnswerTime(username);

	stats.push_back("gamesAmount: " + std::to_string(gamesAmount));
	stats.push_back("rightAnswers: " + std::to_string(rightAnswers));
	stats.push_back("wrongAnswers: " + std::to_string(wrongAnswers));
	stats.push_back("averageAnswerTime: " + std::to_string(averageAnswerTime));

	return stats;
}
