#include "LoggedUser.h"

//-----------constructor-----------------
LoggedUser::LoggedUser(string username)
{
	this->m_username = username;
}

/*
This function returns the name of the user
Input:None
Output:The name of the user :string
*/
string LoggedUser::getUsername() const
{
	return this->m_username;
}

bool LoggedUser::operator==(LoggedUser other)
{
	return this->m_username == other.m_username;
}

bool LoggedUser::operator<(const LoggedUser other) const
{
	return this->m_username < other.m_username;
}