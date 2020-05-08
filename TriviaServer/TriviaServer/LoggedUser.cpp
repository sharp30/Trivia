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
string LoggedUser::getUsername()
{
	return this->m_username;
}
