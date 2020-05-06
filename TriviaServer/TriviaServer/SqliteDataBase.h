#pragma once
#include "IDatabase.h"
#include "sqlite3.h"
#include <io.h>
#include <exception>

using std::exception;

class SqliteDataBase : IDatabase
{
public:
	SqliteDataBase();
	~SqliteDataBase();
	virtual bool doesUserExist(string username);
	virtual bool doesPasswordMatch(string password);
	virtual void addNewUser(string username, string password, string email);

private:
	const string DB_NAME = "OurDB.sqlite.db";
	sqlite3* _dataBase;
};
