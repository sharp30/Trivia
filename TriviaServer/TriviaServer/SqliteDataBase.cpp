#include "SqliteDataBase.h"

SqliteDataBase::SqliteDataBase()
{
	int fileExist = _access(this->DB_NAME.c_str(), 0);
	int res = sqlite3_open(this->DB_NAME.c_str(), &this->_dataBase);

	if (res != SQLITE_OK || fileExist != 0) // failed to open || file doesn't exist, need to be initialized
	{
		this->_dataBase = nullptr;
		throw exception("Failed to open DB");
	}

	//Opened Successfully
}


SqliteDataBase::~SqliteDataBase()
{
	sqlite3_close(this->_dataBase);
	this->_dataBase = nullptr;
}

/*
The function will check if a user exists in the database by his username and password
input: the user's username and password
output: true or false whether the user exists or doesn't exist
*/
bool SqliteDataBase::doesUserExist(string username, string password)
{
	bool rValue = false;

	std::string sqlStatement = "SELECT * FROM Users "
		"WHERE USERNAME = \"" + username + "\" AND PASSWORD = \"" + password + "\";";

	try
	{
		executeCommand(sqlStatement.c_str(), callbackCheckExistence, &rValue);
	}
	catch (std::exception er)
	{
		throw er;
	}
	

	return rValue;
}


/*
The funtion will add a new user to the users database
input: user's details
output: none
*/
void SqliteDataBase::addNewUser(string username, string password, string email)
{
	//TODO: fill this function
}

/*
The function will get sql statement and execute it on the db of the class
input: sql statement
output: none
*/
void SqliteDataBase::executeCommand(const char* statement, int(*callback)(void*, int, char**, char**), void* arg)
{
	int res = 0;

	char** errMessage = nullptr;
	res = sqlite3_exec(this->_dataBase, statement, callback, arg, errMessage);

	if (res != SQLITE_OK)
	{
		throw std::exception("Error in excecuting command on database");
	}
}

/*
The function will check if a sql statement returns 1 value or more
input: the list to set, number of fields, strings with the data, strings with fields names
output: 0 if succeeded
*/
int SqliteDataBase::callbackCheckExistence(void* data, int argc, char** argv, char** azColName)
{
	//if this function was called it means that there are 1 or more records
	*(bool*)data = true;
	return 0;
}
