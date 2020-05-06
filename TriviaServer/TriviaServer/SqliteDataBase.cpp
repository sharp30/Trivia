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
The function will check if a user exists in the database by his username
input: the user's username
output: true or false whether the user exists or doesn't exist
*/
bool SqliteDataBase::doesUserExist(string username)
{
	//TODO: fill this function
	return false;
}

/*
The function will check if a user's password matches to a given password
input: a password to check
output: true or false whether the password does/n't match
*/
bool SqliteDataBase::doesPasswordMatch(string username, string password)
{
	//TODO: fill this function
	return false;
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
