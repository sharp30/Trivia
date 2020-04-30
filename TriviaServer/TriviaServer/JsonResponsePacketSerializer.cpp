#include "JsonResponsePacketSerializer.h"


vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(ErrorResponse response)
{
	vector<unsigned char> message; // the whole message
	vector<unsigned char> content; // part 3 of message
	vector<unsigned char> size; // part 2 of message
	unsigned char code = 0; // part 1 of message, TODO: get code
	int bytesNum = 0; // the number of bytes the message takes
	json j = response;
	
	content = json::to_bson(j);
	bytesNum = content.size();
	size = castSizeToBin(bytesNum);

	//build the final message
	message.push_back(code);
	message.insert(message.end(), size.begin(), size.end());
	message.insert(message.end(), content.begin(), content.end());

	return message;
}

//TODO: fit this function to the first one
vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(LoginResponse response)
{
	json j = response;

	vector<unsigned char> bytes;
	bytes = json::to_bson(j);

	return bytes;
}

//TODO: fit this function to the first one
vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(SignupResponse response)
{
	json j = response;

	vector<unsigned char> bytes;
	bytes = json::to_bson(j);

	return bytes;
}

/*
The function will cast an integer into vector of bytes with 4 elements.
Example= 5 --> [00000000,00000000,00000000,00000101]
input: a size to convert
output: a converted size presented as a binary sequence with 4 bytes
*/
vector<unsigned char> JsonResponsePacketSerializer::castSizeToBin(int size)
{
	//TODO: create this definition
	return vector<unsigned char>();
}
