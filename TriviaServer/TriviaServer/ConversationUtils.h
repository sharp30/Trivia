#pragma once
#include <WinSock2.h>
#include <Windows.h>

#include <vector>
#include "json.hpp"

using nlohmann::json;
using std::vector;

class ConversationUtils
{
public:
	
	static void receiveFromSocket(SOCKET sock, char* buff, int length) throw();
	static vector<unsigned char> castBuffToVector(char* buff, int size);
	static json castBinToJson(vector<unsigned char> buff);
	static vector<unsigned char> castJsonToBin(json j);
	static int castBinToInt(vector<unsigned char> buff);
	static vector<unsigned char> castIntToBin(int value);
private:
    ConversationUtils() = default;  // beacuse it's a static class
	
};