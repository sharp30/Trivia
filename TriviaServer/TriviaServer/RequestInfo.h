#pragma once
#include <ctime>
#include <chrono>
#include <vector>
#include "json.hpp"
#include "ConversationUtils.h"

using std::vector;
using nlohmann::json;

class RequestInfo
{
public:
	//----------------------constructors------------------

	//RequestInfo(int id, time_t time, vector<unsigned char> buff);
	RequestInfo(int id, std::vector<unsigned char> buff,int size);
	//RequestInfo(nlohmann::json j); -- as optional for the future

	//---------------------getters------------------------
	int getId();
	time_t getTime();
	json getBuffer();

protected:
	int _id;
	time_t _receivalTime;
	json _buffer;
};