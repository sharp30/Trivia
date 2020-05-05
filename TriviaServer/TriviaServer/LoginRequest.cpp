#include "LoginRequest.h"

//-------------constructor--------------------
LoginRequest::LoginRequest(nlohmann::json j)
{
<<<<<<< HEAD
	this->_username = j.at("username").get<string>();
	this->_password = j.at("password").get<string>();
=======
	//this->_username = j.at("username").value;
	//this->_password = j.at("password").value;
>>>>>>> 5cb4dfbc28df8ab98fdc2f71673f8ab7c0df307c
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

