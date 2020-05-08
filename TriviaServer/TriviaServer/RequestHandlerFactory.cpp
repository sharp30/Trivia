#include "RequestHandlerFactory.h"

/*
-------------------------------Creating function---------------------------------
Important Note : The function  allcoates dinamically beacuse this is the only option to return pointer of object that was created in a function.
Moreover we don't have interest of returning by value/*


/*
This function creates an LoginRequestHandler on the heap memory and returns it's address
Input:None
Output:The address of the instance :LoginRequestHandler*
*/
LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
	return new LoginRequestHandler();
}

/*
This function creates an MenuRequestHandler on the heap memory and returns it's address
Input:None
Output:The address of the instance :MenuRequestHandler*
*/
MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandler()
{
	return new MenuRequestHandler();
}

/*
This function returns reference to the login Manager
Input:None
Output:reference to the login manager
*/
LoginManager& RequestHandlerFactory::getLoginManager()
{
	return this->m_loginManger;
}
