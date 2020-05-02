#include "signupResponse.h"


SignupResponse::SignupResponse(int _status)
{
	this->status = _status;
	this->messageCode = 101;
}

/*
The function will cast a signup response to JSON format
input: none
output: json format of this object
*/
json SignupResponse::castToJson() const
{
	return json{ {"status", this->status} };
}
