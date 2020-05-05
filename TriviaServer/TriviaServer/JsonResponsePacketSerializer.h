#pragma once

#include <vector>
#include <string>
#include <bitset>
#include "Response.h"
#include "json.hpp"

using std::string;
using std::vector;
using nlohmann::json;
using std::bitset;


class JsonResponsePacketSerializer
{
public:
	
	static vector<unsigned char> serializeResponse(Response* response);

private:

	static vector<unsigned char> castSizeToBin(int size);
	static vector<unsigned char> castMsgCodeToBin(int msgCode);

};