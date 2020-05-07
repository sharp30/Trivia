#pragma once
#include <string>

using std::string;

class IDatabase
{
public:
	virtual bool doesUserExist(string username, string password) = 0;
	virtual void addNewUser(string username, string password, string email) = 0;
};
