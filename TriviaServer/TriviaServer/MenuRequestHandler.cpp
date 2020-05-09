#include "MenuRequestHandler.h"
//-----------------constructor---------
MenuRequestHandler::MenuRequestHandler(RequestHandlerFactory* factory) :IRequestHandler(factory)
{
}
//Empty for now
bool MenuRequestHandler::isRequestRelevant(RequestInfo)
{
	return true;
}

RequestResult MenuRequestHandler::handleRequest(RequestInfo)
{
	return RequestResult();
}
