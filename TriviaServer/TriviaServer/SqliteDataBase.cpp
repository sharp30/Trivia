#include "SqliteDataBase.h"
#include <ctime>
#include <chrono>
#include <cstdlib>
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

/*
The function will find the ID of a user by his username
input: user's name
output: the ID of the user
*/
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

/*
the function will calculate the points of a user and add him to the best players table if needed
--NOTE: this function should be called for each user after a game is finished!!--
input: player's username
output: none
*/
void SqliteDataBase::addPlayerToBestPlayers(string username) throw()
{
	vector<string> best = getBestPlayers();
	bool isOneOfTheBest = true;
	std::reverse(best.begin(), best.end());
	int points = calcPoints(username);

	if (stoi(best.begin()->substr(best.begin()->rfind(':') + 1)) > points)
		throw std::exception("player is not one of the best players");

	//insert user to Users
	std::string sqlStatement = "INSERT INTO Best_Players (Player_Name, Points) "
		"VALUES (\"" + username + "\", " + std::to_string(points) + ");";
	
	executeCommand(sqlStatement.c_str());
	cleanBestPlayersTable();
}

//TODO -DOCUMENTATION
float SqliteDataBase::getPlayerAverageAnswerTime(string username)
{
	std::string sqlStatement= "SELECT AVG(Answer_Time) FROM Players_Answers WHERE User_Id = " + std::to_string(this->getUserID(username)) + ";";
	float amount = 0;
	
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

	executeCommand(sqlStatment.c_str(), callbackGetIntegerValue,&amount);
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
The function will return the names of the 5 best players according to their points in the following format:
			vector: {"playername:points","playername:points","playername:points"}
input: none
output: vector of details as described below
*/
vector<string> SqliteDataBase::getBestPlayers()
{
	string sqlStatement = "SELECT * FROM Best_Players ORDER BY Points DESC LIMIT 5;";
	vector<string> result;

	executeCommand(sqlStatement.c_str(), callbackGetBestPlayers, &result);
	
	return result;
}

/*
The function will calculate the general score of a user - each right answer equals 1 point
input: a user's username
output: user's score
*/
int SqliteDataBase::calcPoints(string username)
{
	//TODO: in the future, change the way of score calculating
	int points = 0;
	int userId = getUserID(username);

	string sqlStatement = "SELECT COUNT(DISTINCT Id) FROM Players_Answers WHERE User_Id = " + std::to_string(userId) + " "
		"AND Is_Correct = 1;";

	executeCommand(sqlStatement.c_str(), callbackGetIntegerValue, &points);
	return points;
}
/*
This funcion creates a new Game into to the database
Input: None
Output:The id of the new Game
*/
int SqliteDataBase::createGame()
{
	//Status: 1 - playing, 0 - closed

	//TODO: Solve Sqltime Problem
	std::time_t start_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	string sql = "INSERT INTO Games (Status,Start_Time) Values(1,"+ std::string(ctime(&start_time)) + ");";
	executeCommand(sql.c_str());

	return sqlite3_last_insert_rowid(this->_dataBase);
}
/*
This function builds a randomized question list for the game
Input: amount - The amount of questions
Output:The vector of the questions
*/
vector<Question> SqliteDataBase::buildQuestions(int amount)
{
	vector<Question> questions;
	vector<int> questions_id;
	int firstQuestionId = 51;//GetFirst();
	int lastQuestionId = 145; //GetLast();
	srand(time(NULL));
	while (questions_id.size() < amount || amount > lastQuestionId-firstQuestionId+1)
	{
		int id = rand() % (lastQuestionId - firstQuestionId + 1) + firstQuestionId;
		while (std::find(questions_id.begin(), questions_id.end(), id) != questions_id.end())
			id = rand() % (lastQuestionId - firstQuestionId + 1) + firstQuestionId;
		questions_id.push_back(id);

		string sql = "SELECT * FROM Questions WHERE Id =" + std::to_string(id) + ";";
		executeCommand(sql.c_str(), callbackBuildQuestions,&questions);
	}
	return questions;
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

/*
This function inserts the result from the sql statement to variable in data
Input:pointer to vector of string, number of fields, strings with the data, strings with fields names
Output: 0 if succeededs
*/
int SqliteDataBase::callbackGetBestPlayers(void* data, int argc, char** argv, char** azColName)
{
	string record = argv[0];
	record += ":";
	record += argv[1];

	((vector<string>*)data)->push_back(record);

	return 0;
}

/*
This function inserts the result from the sql statement to variable in data
Input:pointer to vector of Question, number of fields, strings with the data, strings with fields names
Output: 0 if succeededs
*/
int SqliteDataBase::callbackBuildQuestions(void* data, int argc, char** argv, char** azColName)
{
	string question = argv[1];
	vector<string> answers;
	for (size_t i = 0; i < 4; i++)
	{
		answers.push_back(argv[i + 4]);
	}
	((vector<Question>*)data)->push_back(Question(question, answers));
	return 0;
}

/*
The function will make sure that the best players table holds 5 records only!
input: none
output: none
*/
void SqliteDataBase::cleanBestPlayersTable()
{
	string subSqlStatement = "SELECT Points FROM Best_Players "
		"ORDER BY Points DESC "
		"LIMIT 1 OFFSET 4"; // find the minimum score required to stay in the table
	
	string sqlStatement = "DELETE FROM [Best_Players] WHERE Points < (" + subSqlStatement + ");";
	
	executeCommand(sqlStatement.c_str());
}
