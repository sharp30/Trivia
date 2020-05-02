#pragma once
#include "json.hpp"
#include <string>

using std::string;

class SignupRequest 
{
	//------------constructor------------
	SignupRequest(nlohmann::json j);
	//------------getters--------------
	string getUsername();
	string getPassword();
	string getEmail();

protected:
	string _username;
	string _password;
	string _email;
};