#pragma once

#include "IRequestHandler.h"

class MenuRequestHandler : IRequestHandler
{
public:
	MenuRequestHandler(RequestHandlerFactory* factory);
	virtual bool isRequestRelevant(RequestInfo);
	virtual RequestResult handleRequest(RequestInfo);
protected:
	RequestHandlerFactory* m_handlerFactory;
};