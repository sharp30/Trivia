#pragma once

//#include "LoginRequestHandler.h"
//#include "MenuRequestHandler.h"
#include "LoginManager.h"
#include "IDatabase.h"

class IRequestHandler;
class MenuRequestHandler;
class LoginRequestHandler;

class RequestHandlerFactory
{
public:
	RequestHandlerFactory(IDatabase* database);
	LoginRequestHandler* createLoginRequestHandler();
	MenuRequestHandler* createMenuRequestHandler();
	LoginManager& getLoginManager();

protected:
	LoginManager m_loginManger;
	IDatabase* m_database;
};