#include "MenuRequestHandler.h"

bool MenuRequestHandler::isRequestRelevant(RequestInfo)
{
	return true;
}

RequestResult MenuRequestHandler::handleRequest(RequestInfo)
{
	return RequestResult();
}
