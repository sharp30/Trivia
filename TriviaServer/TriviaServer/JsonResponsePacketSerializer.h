#pragma once

#include <vector>
#include <string>
#include "Responses.h"
#include "json.hpp"

using std::vector;
using nlohmann::json;

class JsonResponsePacketSerializer
{
public:
	static vector<unsigned char> serializeResponse(ErrorResponse e);
	static vector<unsigned char> serializeResponse(LoginResponse e);
	static vector<unsigned char> serializeResponse(SignupResponse e);
};