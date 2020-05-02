#include "JsonRequestPacketDeserializer.h"

#include "json.hpp"
#include <cmath>
using nlohmann::json;

/*
This function Deserializes the request from binary to RequestInfo
Input:buffer - the request in binary
Output:Object of RequestInfo
*/
RequestInfo JsonRequestPacketDeserializer::deserializeRequestInfo(vector<unsigned char> buff)
{
	//parts from buffer 
	vector<unsigned char> binId = { buff.begin(), buff.begin() + 1 }; 
	vector<unsigned char> binSize = { buff.begin() +1, buff.begin() +4 };
	vector<unsigned char> binContent = { buff.begin() +4, buff.end()};

	return RequestInfo(castBinToInt(binId), castBinToInt(binSize), binContent);
}

/*
This function deserializes from binary json to LoginRequest
Input: The request in binary
Output: object of LoginRequst
*/
LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(vector<unsigned char> buff)
{
	json j = json::from_bson(buff);
	return LoginRequest(j);
}

/*
This function deserializes from binary json to SignupRequest
Input: The request in binary
Output: object of SignupRequst
*/
SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(vector<unsigned char> buff)
{
	json j = json::from_bson(buff);
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
