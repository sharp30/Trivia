#pragma once
#include "LoginRequest.h"
#include "SignupRequest.h"
#include "RequestInfo.h" 
#include <vector>
using std::vector;

class JsonRequestPacketDeserializer
{
public:
	static RequestInfo deserializeRequestInfo(vector<unsigned char> buff);
	static LoginRequest deserializeLoginRequest(RequestInfo buff);
	static SignupRequest deserializeSignupRequest(RequestInfo buff);
private:
	JsonRequestPacketDeserializer() = default;  // beacuse it's a static class
};