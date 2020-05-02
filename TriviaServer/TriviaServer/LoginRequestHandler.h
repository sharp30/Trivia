#pragma once
#include "IRequestHandler.h"

//empty class for this version

class LoginRequestHandler : IRequestHandler
{
public:
	virtual bool isRequestRelevant(RequestInfo request);
	virtual RequestResult handleRequest(RequestInfo request);
protected:
	///temporaly only
	static const int LOGIN_CODE = 100;
	static const int  SIGNUP_CODE = 200;
};