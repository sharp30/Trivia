#pragma once
#include <string>
#include <vector>
#include "Question.h"
using std::string;
using std::vector;

class IDatabase
{
public:
	virtual bool doesUserExist(string username, string password) = 0;
	virtual void addNewUser(string username, string password, string email) = 0;
	virtual void addPlayerToBestPlayers(string username) = 0;

	//statistics
	virtual float getPlayerAverageAnswerTime(string username) = 0;
	virtual int getNumOfCorrectAnswers(string username) = 0;
	virtual int getNumOfTotalAnswers(string username) = 0;
	virtual int getNumOfPlayerGames(string username) = 0;
	virtual vector<string> getBestPlayers() = 0;
	virtual int calcPoints(string username) = 0;


	//game

	virtual int createGame() = 0;
	virtual vector<Question> buildQuestions(int amount) = 0;
};
