#pragma once

#include <string>
#include "json.hpp"


using std::string;

class LoginRequest  
{
public:
public:
	LoginRequest(nlohmann::json j);
	string getUsername();
	string getPassword();

protected:
	string _username;
	string _password;
};