#pragma once
#include "RequestInfo.h"
#include "RequestResult.h"
#include "RequestHandlerFactory.h"

//abstract class
class IRequestHandler
{
public:
	IRequestHandler(RequestHandlerFactory* factory);
	virtual bool isRequestRelevant(RequestInfo) = 0;
	virtual RequestResult handleRequest(RequestInfo) = 0;
protected:
	RequestHandlerFactory* m_handlerFactory;
};