#include "MenuRequestHandler.h"
//-----------------constructor---------
MenuRequestHandler::MenuRequestHandler(RequestHandlerFactory* factory) :IRequestHandler(factory)
{
}
//Empty for now
bool MenuRequestHandler::isRequestRelevant(RequestInfo info)
{
	return info.getId() == MSG_CODE;
}

RequestResult MenuRequestHandler::handleRequest(RequestInfo info)
{
	//TODO: connnect stats manager in here and get details from it.
	return RequestResult();
}
