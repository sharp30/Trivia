#pragma once

#include <vector>
#include <string>
#include <bitset>
#include "Message.h"
#include "json.hpp"

using std::string;
using std::vector;
using nlohmann::json;
using std::bitset;


class JsonResponsePacketSerializer
{
public:
	static vector<unsigned char> serializeResponse(Message* response);

private:
	static vector<unsigned char> castSizeToBin(int size);

};