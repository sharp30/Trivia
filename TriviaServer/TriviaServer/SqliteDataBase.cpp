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

/*
The d'tor will close the data base
*/
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

//returns id of user - //TODO
int SqliteDataBase::getUserID(string username)
{
	string sqlStatement = "SELECT ID FROM USERS WHERE USERNAME = \"" + username + "\";";
	int id = 0;
	try
	{
		executeCommand(sqlStatement.c_str(), callbackGetIntegerValue, &id);
	}
	catch(std::exception er)
	{
		throw er;
	}

	return id;
}


/*
The funtion will add a new user to the users database
input: user's details
output: none
*/
void SqliteDataBase::addNewUser(string username, string password, string email)
{
	//insert user to Users
	std::string sqlStatement = "INSERT INTO Users (USERNAME, PASSWORD, EMAIL) "
		"VALUES (\"" + username + "\", \"" + password + "\", \"" + email + "\");";
	try
	{
		executeCommand(sqlStatement.c_str());
	}
	catch (std::exception er)
	{
		throw er;
	}
}
//TODO -DOCUMENTATION
int SqliteDataBase::getPlayerAverageAnswerTime(string username)
{
	std::string sqlStatement= "SELECT AVG(Answer_Time) FROM Players_Answers WHERE User_Id = " + std::to_string(this->getUserID(username)) + ";";
	int amount = 0;

	executeCommand(sqlStatement.c_str(), callbackGetIntegerValue, &amount);
	return amount;

}
//TODO -DOCUMENTATION
int SqliteDataBase::getNumOfCorrectAnswers(string username)
{
	std::string sqlStatement = "SELECT COUNT(ID) FROM Players_Answers WHERE Is_Correct = 1  AND  User_Id =" + std::to_string(this->getUserID(username)) + ";";
	int amount = 0;

	executeCommand(sqlStatement.c_str(), callbackGetIntegerValue, &amount);
	return amount;
}
/*
This function returns the total amount of answers of a specific user
Input:The name of the user : string
Output:The amount : int
*/
int SqliteDataBase::getNumOfTotalAnswers(string username)
{
	std::string sqlStatment = "SELECT COUNT(Game_Id) FROM Players_Answers WHERE User_Id =" + std::to_string(this->getUserID(username)) + ";";
	int amount = 0;

	executeCommand(sqlStatment.c_str(), callbackGetIntegerValue, &amount);
	return amount;
}

//TODO - documentation
int SqliteDataBase::getNumOfPlayerGames(string username)
{
	string sqlStatement = "SELECT COUNT(DISTINCT Game_Id) FROM Players_Answers WHERE User_Id = " + std::to_string(getUserID(username)) + ";";
	int amount = 0;
	executeCommand(sqlStatement.c_str(), callbackGetIntegerValue, &amount);
	return amount;
}

/*
The function will get sql statement and execute it on the db of the class
input: sql statement
output: true or false if everything went fine
*/
void SqliteDataBase::executeCommand(const char* statement)
{
	int res = 0;

	char** errMessage = nullptr;
	res = sqlite3_exec(this->_dataBase, statement, nullptr, nullptr, errMessage);

	if (res != SQLITE_OK)
	{
		throw std::exception("Error in excecuting command on database");
	}
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

/*
This function inserts the result from the sql statement to variable in data
Input:pointer to int, number of fields, strings with the data, strings with fields names
Output:0 if succeededs
*/
int SqliteDataBase::callbackGetIntegerValue(void* data, int argc, char** argv, char** azColName)
{
	*(int*)data = std::stoi(argv[0]);
	//maybe add some checking here
	return 0;
}

