#include "LoginResponse.h"

LoginResponse::LoginResponse(int _status)
{
	this->status = _status;
	this->messageCode = 201;
}

/*
The function will cast a login response to JSON format
input: none
output: json format of this object
*/
json LoginResponse::castToJson() const
{
	return json{ {"status", this->status} };
}
