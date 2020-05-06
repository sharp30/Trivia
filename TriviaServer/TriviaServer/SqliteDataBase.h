#pragma once
#include "IDatabase.h"
#include "sqlite3.h"

class SqliteDataBase : IDatabase
{
public:
	virtual bool doesUserExist(string username);
	virtual bool doesPasswordMatch(string password);
	virtual void addNewUser(string username, string password, string email);

private:
	sqlite3* _dataBase;
};
