#include "JsonRequestPacketDeserializer.h"

#include "json.hpp"
#include <cmath>

using nlohmann::json;

/*
This function Deserializes the request from binary to RequestInfo
Input:buffer - the request in binary
Output:Object of RequestInfo

RequestInfo JsonRequestPacketDeserializer::deserializeRequestInfo(vector<unsigned char> buff)
{
	const int ID_LENGTH = 1;
	const int SIZE_LENGTH = 4;
	//parts from buffer 
	vector<unsigned char> binId = { buff.begin(), buff.begin() + ID_LENGTH }; 
	vector<unsigned char> binSize = { buff.begin() +ID_LENGTH, buff.begin() +ID_LENGTH + SIZE_LENGTH};
	vector<unsigned char> binContent = { buff.begin() +ID_LENGTH + SIZE_LENGTH, buff.end()};
	int size = castBinToInt(binSize); //not relevant for now
	time_t nowTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); // the time now
	return RequestInfo(castBinToInt(binId), nowTime, binContent);
}
/*

/*
This function deserializes from binary json to LoginRequest
Input: The request in binary
Output: object of LoginRequst
*/
LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(vector<unsigned char> buff)
{
	unsigned char* cBuff = &(*buff.begin());
	json j = nlohmann::json::parse(cBuff, cBuff +buff.size());
	//json j = json::from_bson(buff);;
	return LoginRequest(j);
}

/*
This function deserializes from binary json to SignupRequest
Input: The request in binary
Output: object of SignupRequst
*/
SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(vector<unsigned char> buff)
{
	unsigned char* cBuff = &(*buff.begin());
	json j = nlohmann::json::parse(cBuff, cBuff + buff.size());
	return SignupRequest(j);
}


/*
This function converts from binary to integer value
For Example:0111 ==> 7
Input : bin - vector of chars: the value in binary
Output:The integer value
*/
int JsonRequestPacketDeserializer::castBinToInt(vector<unsigned char> bin)
{
	const int COUNTING_BASE = 2; //The binary base ==> 2
	int val = 0;

	for (int i =0; i < bin.size(); i++)
	{
		int bit = bin[i] - '0';
		val += pow(2, bin.size() - i - 1) * bit;
	}

	return val;
}
