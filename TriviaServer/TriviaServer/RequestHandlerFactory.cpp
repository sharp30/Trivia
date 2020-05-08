#include "RequestHandlerFactory.h"
/*
This function creates an LoginRequestHandler on the heap and returns it's destination
Input:None
Output:The address of the instance :LoginRequestHandler*

Important Note:The function  allcoates dinamically beacuse this is the only option to return pointer of object that was created in a function.
Moreover we don't have interest of returning by value
*/
LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
	return new LoginRequestHandler();
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
