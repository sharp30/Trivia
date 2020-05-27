#pragma once
#include <string>

using std::string;

class IDatabase
{
public:
	virtual bool doesUserExist(string username, string password) = 0;
	virtual void addNewUser(string username, string password, string email) = 0;
	
	//statistics
	virtual int getPlayerAverageAnswerTime(string username) = 0;//game?
	virtual int getNumOfCorrectAnswers(string username) = 0;
	virtual int getNumOfTotalAnswers(string username) = 0; //game?
	virtual int getNumOfPlayerGames(string username) = 0;
};
