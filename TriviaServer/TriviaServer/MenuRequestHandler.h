#pragma once

#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"
#include "StatisticsManager.h"
//class RequestHandlerFactory;

class MenuRequestHandler : IRequestHandler
{
public:
	MenuRequestHandler(RequestHandlerFactory* factory);
	virtual bool isRequestRelevant(RequestInfo);
	virtual RequestResult handleRequest(RequestInfo);
protected:

	static const int MSG_CODE = 15;
	static const int STATS_REQ_CODE = 70; // the message code of a getStatistics request

};