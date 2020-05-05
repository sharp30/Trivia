#include "LoginRequestHandler.h"

#include "LoginResponse.h"
#include "SignupResponse.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include "ConversationUtils.h"


/*
This function checks if the request relevant to the handler
Input: request : The request that was Sent :RequestInfo
Output:Boollean value - if the request is relevant to the login handler
*/
bool LoginRequestHandler::isRequestRelevant(RequestInfo request)
{

	return request.getId() == LOGIN_CODE || request.getId() == SIGNUP_CODE;
}


/*
This function handles a request and returns the result of the request
Input: request: The request that was sent:RequestInfo
Output:The result of the request : RequestResult
*/
RequestResult LoginRequestHandler::handleRequest(RequestInfo request)
{
	RequestResult res;
	if (request.getId() == LOGIN_CODE)
	{
		LoginRequest req(request.getBuffer());
		LoginResponse rep(1);
		res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&rep);
	}
	else
	{
		SignupRequest req(request.getBuffer());
		SignupResponse rep(1);
		res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&rep);
	}

	res._newHandler = nullptr; //should do something in the future.
	return res;
}


