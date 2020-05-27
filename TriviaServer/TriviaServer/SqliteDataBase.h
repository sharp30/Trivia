#pragma once
#include "IDatabase.h"
#include "sqlite3.h"
#include <io.h>
#include <exception>

using std::exception;

class SqliteDataBase : IDatabase
{
public:
	SqliteDataBase() throw();
	~SqliteDataBase();
	
	virtual bool doesUserExist(string username, string password) throw();
	virtual void addNewUser(string username, string password, string email) throw();
	
	//statistics
	virtual int getPlayerAverageAnswerTime(string username);//game?
	virtual int getNumOfCorrectAnswers(string username);
	virtual int getNumOfTotalAnswers(string username); //game?
	virtual int getNumOfPlayerGames(string username);
private:
	const string DB_NAME = "OurDB.sqlite"; 
	sqlite3* _dataBase;
	int getUserID(string username) throw();
	void executeCommand(const char* statement) throw();
	void executeCommand(const char* statement, int (*callback)(void*, int, char**, char**), void* arg) throw();
	static int callbackCheckExistence(void* data, int argc, char** argv, char** azColName);
	static int callbackGetIntegerValue(void* data, int argc, char** argv, char** azColName);
};
