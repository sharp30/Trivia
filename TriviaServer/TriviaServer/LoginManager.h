#pragma once
#include "IDatabase.h"

class LoginManager
{
public:
	void signup(string username, string password, string email) throw();
	void login(string username, string password) throw();
	void logout(string username) throw();

private:
	IDatabase* m_database;
	//TODO: add loggedUsers vector here.
};