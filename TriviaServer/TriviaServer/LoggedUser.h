#pragma once

#include <string>

using std::string;

class LoggedUser
{
public:	
	LoggedUser(string user);
	string getUsername();

protected:
	string m_username;
};