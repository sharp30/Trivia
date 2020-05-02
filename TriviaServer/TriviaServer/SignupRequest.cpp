#include "SignupRequest.h"

SignupRequest::SignupRequest(nlohmann::json j)
{
	this->_username = j.at["username"];
	this->_password = j.at["password"];
	this->_email= j.at["email"];
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


