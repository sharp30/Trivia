#pragma once

#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"
//#TODO: include all relevant requests

class GameRequestHandler : IRequestHandler
{
public:
	GameRequestHandler(RequestHandlerFactory* factory,LoggedUser user);
	virtual bool isRequestRelevant(RequestInfo);
	virtual RequestResult handleRequest(RequestInfo);
	using handler_func = RequestResult(GameRequestHandler::*)(RequestInfo);

protected:
	RequestResult getQuestion(RequestInfo);
	RequestResult submitAnswer(RequestInfo info);
	RequestResult getGameResults(RequestInfo info);
	RequestResult leaveGame(RequestInfo info);
	
	//Game m_game;
	LoggedUser m_user;
	//GameManager& m_gameManager;
	
	static const std::map<int, handler_func> m_functions;
};
