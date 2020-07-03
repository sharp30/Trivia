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

//TODO: fill these functions after combining game manager and Game classes

//-----------------constructor--------------------
GameRequestHandler::GameRequestHandler(RequestHandlerFactory* factory ,LoggedUser user) : IRequestHandler(factory), m_user(user)
{
}

bool GameRequestHandler::isRequestRelevant(RequestInfo info)
{
	return m_functions.find(info.getId()) != m_functions.end();
}

RequestResult GameRequestHandler::handleRequest(RequestInfo info)
{
	return (this->*m_functions.at(info.getId()))(info);
}

RequestResult GameRequestHandler::getQuestion(RequestInfo info)
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
