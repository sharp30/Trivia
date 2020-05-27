#include "StatisticsManager.h"
#include <algorithm>
#include <cassert>
//------------constructor------------
StatisticsManager::StatisticsManager(IDatabase* database)
{
	this->m_database = database;
}
/*
The function will signup a new user to the system -> send it's details to the DB
input: user's details (username, password, email)
output: none
*/
void StatisticsManager::signup(string username, string password, string email) throw()
{
	try
	{
		//does the user exist in the database.
		if (m_database->doesUserExist(username, password))
		{
			throw std::exception((username + "is already exists").c_str());
		}

		this->m_database->addNewUser(username, password, email);
	}
	catch (std::exception er)
	{
		throw er;
	}
	
}