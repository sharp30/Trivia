#include "ErrorResponse.h"


ErrorResponse::ErrorResponse(string errMessage)
{
	this->errorMessage = errMessage;
	this->messageCode = 301;
}

/*
The function will cast an error response to JSON format
input: none
output: json format of this object
*/
json ErrorResponse::castToJson() const
{
	return json{ {"message", this->errorMessage} };
}