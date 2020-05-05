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
	static vector<unsigned char> castIntToBin(int msgCode, int requiredBytes) throw();
	static vector<int> length_to_dec_sequence(int size, int requiredBytes);

};