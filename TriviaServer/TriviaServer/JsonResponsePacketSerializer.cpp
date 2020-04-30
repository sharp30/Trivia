#include "JsonResponsePacketSerializer.h"

/*
The function will serialize a response object to a binary buffer that will be sent to the user
input: a response object
output: buffer that will be sent to the user
*/
vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(Message* response)
{
	vector<unsigned char> message; // the whole message
	vector<unsigned char> content; // part 3 of message
	vector<unsigned char> size; // part 2 of message
	unsigned char code = response->getMsgCode(); // part 1 of message, TODO: get code
	json j = response->castToJson();

	content = json::to_bson(j);
	size = castSizeToBin(content.size());

	//build the final message
	message.push_back(code);
	message.insert(message.end(), size.begin(), size.end());
	message.insert(message.end(), content.begin(), content.end());

	return message;
}

/*
The function will cast an integer into vector of bytes with 4 elements.
Example= 5 --> [00000000 00000000 00000000 00000101]
input: a size to convert
output: a converted size presented as a binary sequence with 4 bytes
*/
vector<unsigned char> JsonResponsePacketSerializer::castSizeToBin(int size)
{
	const int NUMBER_OF_BITS = 32; // 8 bits * 4
	string sizeInBinary = bitset<NUMBER_OF_BITS>(size).to_string();
	vector<unsigned char> result;

	for (string::iterator it = sizeInBinary.begin(); it != sizeInBinary.end(); it++)
	{
		result.push_back((unsigned char)*it);
	}

	return result;
}
