#pragma once

#include "LoginRequestHandler.h"
#include "MenuRequestHandler.h"
class RequestHandlerFactory
{
public:
	LoginRequestHandler* createLoginRequestHandler();
	//LoginManager
	void getLoginManager() {};
protected:
	// login manager
	//database
};