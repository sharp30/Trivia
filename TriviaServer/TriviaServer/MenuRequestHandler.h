#pragma once

#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"
//class RequestHandlerFactory;

class MenuRequestHandler : IRequestHandler
{
public:
	MenuRequestHandler(RequestHandlerFactory* factory);
	virtual bool isRequestRelevant(RequestInfo);
	virtual RequestResult handleRequest(RequestInfo);
protected:

	static const int MSG_CODE = 15;
};