#include "GameRequestHandler.h"
#include "JsonResponsePacketSerializer.h"
#include "PlayerResults.h"
#include "LogoutResponse.h"
#include "SubmitAnswerResponse.h"

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
	bool actionResult = true;
	RequestResult res;

	try
	{
		//Question q = this.m_game.getQuestionForUser(this.m_user);
	}
	catch (std::exception e)
	{
		actionResult = false;
	}

	//GetQuestionResponse response((int)actionResult, q.getQuestion(), q.getPossibleAnswers());
	//res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);
	//if (actionResult)
		//res.setNewHandler((IRequestHandler*)this->m_handlerFactory->createGameRequestHandler();
	return res;
}

RequestResult GameRequestHandler::submitAnswer(RequestInfo info)
{
	//SubmitAnswerRequest request(info.getBuffer());
	
	bool actionResult = true;
	RequestResult res;

	try
	{
		//this.m_game.submitAnswer(this.m_user, request.getAnswerId);
	}
	catch (std::exception e)
	{
		actionResult = false;
	}

	//Question q = this.m_game.getQuestionForUser(this.m_user);
	//SubmitAnswerResponse response((int)actionResult);
	//res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);
	//if (actionResult)
		//res.setNewHandler((IRequestHandler*)this->m_handlerFactory->createGameRequestHandler();
	return res;
}

RequestResult GameRequestHandler::getGameResults(RequestInfo info)
{
	RequestResult res;

	//GetGameResultsResponse response((int)actionResult, this.m_game.getGameResults());
	//res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);

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
		//this.m_game.removePlayer(this.m_user);
	}
	catch (std::exception e)
	{
		actionResult = false;
	}

	//LeaveGameResponse response((int)actionResult);
	//res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);
	//if (actionResult)
		//res.setNewHandler((IRequestHandler*)this->m_handlerFactory->createMenuRequestHandler(this.m_user.getUsername());
	return res;
}
