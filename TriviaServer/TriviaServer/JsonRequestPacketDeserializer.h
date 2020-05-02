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
	static LoginRequest deserializeLoginRequest(vector<unsigned char> buff);
	static SignupRequest deserializeSignupRequest(vector<unsigned char> buff);

private:
	JsonRequestPacketDeserializer() = default;  // beacuse it's a static class
	static int castBinToInt(vector<unsigned char> bin);
};