#pragma once
#include "IRequestHandler.h"
#include "LoginRequest.h"
#include "SignupRequest.h"
#include "LoginManager.h"
#include "RequestHandlerFactory.h"
#include "JsonResponsePacketSerializer.h"
#include "ConversationUtils.h"
#include "LoginResponse.h"
#include "SignupResponse.h"
//empty class for this version

class LoginRequestHandler : IRequestHandler
{
public:
	LoginRequestHandler(RequestHandlerFactory* factory);
	virtual bool isRequestRelevant(RequestInfo request);
	virtual RequestResult handleRequest(RequestInfo request);

protected:
	//RequestResult login(LoginRequest req);
	//RequestResult signup(SignupRequest req);
	///temporaly only--should be in other place.
	
	static const int LOGIN_CODE = 20;
	static const int SIGNUP_CODE = 10;
};