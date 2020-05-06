#pragma once

#include "IRequestHandler.h"

class MenuRequestHandler : IRequestHandler
{
public:
	virtual bool isRequestRelevant(RequestInfo);
	virtual RequestResult handleRequest(RequestInfo);
};