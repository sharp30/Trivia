#pragma once
#include "IDatabase.h"
#include <vector>
#include "LoggedUser.h"

using std::vector;

class LoginManager
{
public:
	LoginManager() = default;
	LoginManager(IDatabase* database);
	void signup(string username, string password, string email) throw();
	void login(string username, string password) throw();
	void logout(string username) throw();

private:
	IDatabase* m_database;
	vector<LoggedUser> m_loggedUsers;
};