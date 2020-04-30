#pragma once

#include <vector>
#include <string>
#include <bitset>
#include "Responses.h"
#include "json.hpp"

using std::string;
using std::vector;
using nlohmann::json;
using std::bitset;

using Responses::Response;
using Responses::ErrorResponse;
using Responses::LoginResponse;
using Responses::SignupResponse;

class JsonResponsePacketSerializer
{
public:
	//static vector<unsigned char> serializeResponse(Response response);
	
	static vector<unsigned char> serializeResponse(ErrorResponse response);
	static vector<unsigned char> serializeResponse(LoginResponse response);
	static vector<unsigned char> serializeResponse(SignupResponse response);

private:
	static vector<unsigned char> castSizeToBin(int size);

};