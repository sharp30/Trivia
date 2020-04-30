#pragma once

#include <vector>
#include <string>
#include "Responses.h"

using std::vector;

class JsonResponsePacketSerializer
{
public:
	static vector<unsigned char> serializeResponse(ErrorResponse e);
	static vector<unsigned char> serializeResponse(LoginResponse e);
	static vector<unsigned char> serializeResponse(SignupResponse e);
};