#include "GameRequestHandler.h"
#include "JsonResponsePacketSerializer.h"
#include "LogoutResponse.h"

const std::map<int, GameRequestHandler::handler_func> GameRequestHandler::m_functions =
{
	{80, &GameRequestHandler::getQuestion},
	{82, &GameRequestHandler::submitAnswer},
	{84, &GameRequestHandler::getGameResults},
	{86, &GameRequestHandler::leaveGame}
};


//-----------------constructor--------------------
GameRequestHandler::GameRequestHandler(RequestHandlerFactory* factory ,LoggedUser user) :IRequestHandler(factory), m_user(user)
{
}

bool GameRequestHandler::isRequestRelevant(RequestInfo)
{
	return false;
}

RequestResult GameRequestHandler::handleRequest(RequestInfo)
{
	return RequestResult();
}

RequestResult GameRequestHandler::getQuestion(RequestInfo)
{
	return RequestResult();
}

RequestResult GameRequestHandler::submitAnswer(RequestInfo info)
{
	return RequestResult();
}

RequestResult GameRequestHandler::getGameResults(RequestInfo info)
{
	return RequestResult();
}

RequestResult GameRequestHandler::leaveGame(RequestInfo info)
{
	return RequestResult();
}
