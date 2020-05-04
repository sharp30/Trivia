#pragma once
//empty interface for now
#include "RequestInfo.h"
#include "RequestResult.h"

//abstract class
class IRequestHandler
{
public:
	virtual bool isRequestRelevant(RequestInfo) = 0;
	virtual RequestResult handleRequest(RequestInfo) = 0;
};