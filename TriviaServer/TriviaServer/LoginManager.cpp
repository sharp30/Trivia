#include "LoginManager.h"
#include <algorithm>
//------------constructor------------
LoginManager::LoginManager(IDatabase* database)
{
	this->m_database = database;
}
/*
The function will signup a new user to the system -> send it's details to the DB
input: user's details (username, password, email)
output: none
*/
void LoginManager::signup(string username, string password, string email) throw()
{
	try
	{
		this->m_database->addNewUser(username, password, email);
	}
	catch (std::exception er)
	{
		throw er;
	}
	
}

/*
The function will login a known user to the system -> send it's details to the DB
input: user's details (username, password)
output: none
*/
void LoginManager::login(string username, string password) throw()
{
	try
	{
		this->m_database->doesUserExist(username, password);
	}
	catch (std::exception er)
	{
		throw er;
	}
}

/*
The function will logout a user from the system ->
	--remove it's element from the users vector
input: user's username
output: none
*/
void LoginManager::logout(string username) throw()
{
	try
	{
		vector<LoggedUser>::iterator place = std::find(this->m_loggedUsers.begin(), this->m_loggedUsers.end(), username); //find place of username in vector
		this->m_loggedUsers.erase(place);
	}
	catch (std::exception er)
	{
                throw er;
	}
}
