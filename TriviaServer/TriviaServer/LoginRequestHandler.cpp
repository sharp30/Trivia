#include "LoginRequestHandler.h"

#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include "ConversationUtils.h"
#include "LoginResponse.h"
#include "SignupResponse.h"



//constructor
LoginRequestHandler::LoginRequestHandler(RequestHandlerFactory* factory) : IRequestHandler(factory)
{

}

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
	bool actionResult = true;//is the login or the signup succeeded
	RequestResult res;
	res._newHandler = nullptr;
	
	LoginManager& man = this->m_handlerFactory->getLoginManager();
	if (request.getId() == LOGIN_CODE)
	{
		LoginRequest req(request.getBuffer());
		try
		{
			man.login(req.getUsername(), req.getPassword());
		}
		catch (std::exception e)
		{
			actionResult = false;
		}
		LoginResponse response((int)actionResult);
		res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);
	}

	else
	{
		SignupRequest req(request.getBuffer());
		try
		{
			man.signup(req.getUsername(),req.getPassword(),req.getEmail());
		}
		catch (std::exception e)
		{
			actionResult = false;
		}
		SignupResponse response(actionResult);
		res._buffer = JsonResponsePacketSerializer::serializeResponse((Response*)&response);
	}

	if(actionResult)
		res._newHandler =(IRequestHandler*)this->m_handlerFactory->createMenuRequestHandler(); //it's doing someting!!!
	
	return res;
}

//is this really the purpose?
/*
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
*/