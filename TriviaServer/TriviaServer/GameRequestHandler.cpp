#include "GameRequestHandler.h"
#include "JsonResponsePacketSerializer.h"
#include "PlayerResults.h"
#include "LogoutResponse.h"
#include "SubmitAnswerResponse.h"
#include "GetQuestionResponse.h"
#include "SubmitAnswerRequest.h"
#include "LeaveGameResponse.h"

const std::map<int, GameRequestHandler::handler_func> GameRequestHandler::m_functions =
{
	{80, &GameRequestHandler::getQuestion},
	{82, &GameRequestHandler::submitAnswer},
	{84, &GameRequestHandler::getGameResults},
	{86, &GameRequestHandler::leaveGame}
};

//TODO: fill these functions after combining game manager and Game classes

//-----------------constructor--------------------
GameRequestHandler::GameRequestHandler(RequestHandlerFactory* factory ,LoggedUser user,int gameId) : IRequestHandler(factory), m_user(user)
{
	this->_gameId = gameId;
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
	bool actionResult = true;
	RequestResult res;
	Question q;
	try
	{
		 q = this->m_handlerFactory->getGameManager().getQuestionForUser(_gameId, m_user);
	}
	catch (std::exception e)
	{
		actionResult = false;
	}

	GetQuestionResponse response((int)actionResult, q.getQuestion(), q.getPossibleAnswers());
	res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);
	if (actionResult)
		res.setNewHandler(nullptr);//same as before
	return res;
}

RequestResult GameRequestHandler::submitAnswer(RequestInfo info)
{
	SubmitAnswerRequest request(info.getBuffer());
	
	bool actionResult = true;
	RequestResult res;

	try
	{
		this->m_handlerFactory->getGameManager().submitAnswer(_gameId, m_user, request.getAnswerId());//add throw in submitAnswer function
	}
	catch (std::exception e)
	{
		actionResult = false;
	}

	SubmitAnswerResponse response((int)actionResult);
	res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);
	if (actionResult)
		res.setNewHandler(nullptr);
	return res;
}

RequestResult GameRequestHandler::getGameResults(RequestInfo info)
{
	RequestResult res;

	//GetGameResultsResponse response((int)actionResult, this.m_game.getGameResults());
	res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);

	//TODO: check if the player should be moved back to menu.
	//res.setNewHandler((IRequestHandler*)this->m_handlerFactory->createMenuRequestHandler(this.m_user.getUsername());
	return res;
}

RequestResult GameRequestHandler::leaveGame(RequestInfo info)
{
	bool actionResult = true;
	RequestResult res;

	try
	{
		this->m_handlerFactory->getGameManager().removePlayer(_gameId, m_user);
	}
	catch (std::exception e)
	{
		actionResult = false;
	}

	LeaveGameResponse response((int)actionResult);
	res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);
	if (actionResult)
		res.setNewHandler((IRequestHandler*)this->m_handlerFactory->createMenuRequestHandler(this->m_user.getUsername());
	return res;
}
