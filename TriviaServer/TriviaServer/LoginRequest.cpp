#include "LoginRequest.h"

//-------------constructor--------------------
LoginRequest::LoginRequest(nlohmann::json j)
{
	this->_username = j.at("username").get<string>();
	this->_password = j.at("password").get<string>();
}

/*
This function returns the password
Input:None
Output:The username ::string
*/
string LoginRequest::getUsername()
{
	return this->_username;
}
/*
This function returns the password
Input:None
Output:The password ::string
*/
string LoginRequest::getPassword()
{
	return  this->_password;
}

