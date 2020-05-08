#include "LoginRequestHandler.h"

#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include "ConversationUtils.h"
#include "LoginResponse.h"
#include "SignupResponse.h"

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
	bool result;
	RequestResult res;
	res._newHandler = nullptr;
	LoginManager man = this->m_handlerFactory->getLoginManager();
	if (request.getId() == LOGIN_CODE)
	{
		LoginRequest req(request.getBuffer());
		man.login(req.getUsername(), req.getPassword());
		//check validaion
	    //res = this->login(req);
		LoginResponse response(result);
		res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);
	}
	else
	{
		SignupRequest req(request.getBuffer());
		res = man.signup(req);
		SignupResponse response(result);
		res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);
	}
	if(result)
	res._newHandler = this->m_handlerFactory->createLoginRequestHandler(); //should do something in the future.
	return res;
}

//is this really the purpose?
RequestResult LoginRequestHandler::login(LoginRequest req)
{
	LoginManager& man = this->m_handlerFactory->getLoginManager();
	a.signup(req.getUsername(),req.getPassword());
	LoginResponse rep(1);
	RequestResult res = { JsonResponsePacketSerializer::serializeResponse((Response*)&rep),nullptr };
	return res;
}

RequestResult LoginRequestHandler::signup(SignupRequest req)
{
		LoginManager& man = this->m_handlerFactory->getLoginManager();
		a.login(req.getUsername(), req.getPassword());
		SignupResponse rep(1);
		RequestResult res = { JsonResponsePacketSerializer::serializeResponse((Response*)&rep),nullptr };
		return res;
}


