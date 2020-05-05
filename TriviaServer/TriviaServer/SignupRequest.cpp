#include "SignupRequest.h"

SignupRequest::SignupRequest(nlohmann::json j)
{
<<<<<<< HEAD
	this->_username = j.at("username").get<string>(); // explanation - get<type> returns copy of the value from json at the requested type
=======
	this->_username = j.at("username").get<string>();
>>>>>>> 5cb4dfbc28df8ab98fdc2f71673f8ab7c0df307c
	this->_password = j.at("password").get<string>();
	this->_email= j.at("email").get<string>();
}

/*
This function returns the username
Input:None
Output:The username : string;
*/
string SignupRequest::getUsername()
{
	return this->_username;
}

/*
This function returns the password 
Input:None
Output:The password:string
*/
string SignupRequest::getPassword()
{
	return this->_email;
}

/*
This function returns the email
Input:None
Output:The email:string
*/
string SignupRequest::getEmail()
{
	return this->_email;
}


