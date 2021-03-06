#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "IDatabase.h"
#include "sqlite3.h"
#include <io.h>
#include <exception>
#include <vector>
#include <algorithm>

using std::exception;
using std::vector;

class SqliteDataBase : IDatabase
{
public:
	SqliteDataBase() throw();
	~SqliteDataBase();
	
	virtual bool doesUserExist(string username, string password) throw();
	virtual void addNewUser(string username, string password, string email) throw();
	virtual void addPlayerToBestPlayers(string username) throw();

	//statistics
	virtual float getPlayerAverageAnswerTime(string username);
	virtual int getNumOfCorrectAnswers(string username);
	virtual int getNumOfTotalAnswers(string username); 
	virtual int getNumOfPlayerGames(string username);
	virtual vector<string> getBestPlayers();
	virtual int calcPoints(string username);

	//game
	virtual int createGame();
	virtual vector<Question> buildQuestions(int amount);
	virtual void submitUserAnswer(int gameId, string username, string question, string anser, bool isCorrect);

private:
	const string DB_NAME = "OurDB.sqlite"; 
	sqlite3* _dataBase;
	int getUserID(string username) throw();
	void executeCommand(const char* statement) throw();
	void executeCommand(const char* statement, int (*callback)(void*, int, char**, char**), void* arg) throw();
	static int callbackCheckExistence(void* data, int argc, char** argv, char** azColName);
	static int callbackGetIntegerValue(void* data, int argc, char** argv, char** azColName);
	static int callbackGetBestPlayers(void* data, int argc, char** argv, char** azColName);
	static int callbackBuildQuestions(void* data, int argc, char** argv, char** azColName);
	void cleanBestPlayersTable();
};
