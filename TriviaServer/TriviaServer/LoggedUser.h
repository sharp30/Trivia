#pragma once

#include <string>

using std::string;

class LoggedUser
{
public:	
	LoggedUser(string user);
	string getUsername();
	bool operator==(LoggedUser others);
	bool operator<(const LoggedUser other)const;

protected:
	string m_username;
};