#include "LogoutResponse.h"


LogoutResponse::LogoutResponse(int _status)
{
	this->status = _status;
	this->messageCode = 101;
}

/*
The function will cast a logout response to JSON format
input: none
output: json format of this object
*/
json LogoutResponse::castToJson() const
{
	return json{ {"status", this->status} };
}
