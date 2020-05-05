#include "JsonResponsePacketSerializer.h"

/*
The function will serialize a response object to a binary buffer that will be sent to the user
input: a response object
output: buffer that will be sent to the user
*/
vector<unsigned char> JsonResponsePacketSerializer::serializeResponse(Response* response)
{
	const int CODE_LEN_BYTES = 1;
	const int SIZE_LEN_BYTES = 4;

	vector<unsigned char> message; // the whole message
	vector<unsigned char> content; // part 3 of message
	vector<unsigned char> size; // part 2 of message
	vector<unsigned char> code = castIntToBin(response->getMsgCode(), CODE_LEN_BYTES); // part 1 of message
	json j = response->castToJson();

	content = json::to_bson(j);
	size = castIntToBin(content.size(), SIZE_LEN_BYTES);

	//build the final message
	message.insert(message.end(), code.begin(), code.end());
	message.insert(message.end(), size.begin(), size.end());
	message.insert(message.end(), content.begin(), content.end());

	return message;
}


/*
The function will cast an integer into vector of bytes with 1 element.
Example= 20 --> [0010100]
input: a size to convert
output: a converted size presented as a binary sequence with 4 bytes
*/
vector<unsigned char> JsonResponsePacketSerializer::castIntToBin(int msgCode, int requiredBytes)
{
	vector<unsigned char> result;
	vector<int> dec_sequence;

	dec_sequence = length_to_dec_sequence(msgCode, requiredBytes);

	for (vector<int>::iterator it = dec_sequence.begin(); it != dec_sequence.end(); it++)
	{
		result.push_back(*it);
	}

	return result;
}


/*
the function will get a decimal integer and cast into 4 bytes integer that will fit the 'bytes' object
EXAMPLE : 400 -- > 0 - 0 - 1 - 90 // 256 --> 0-0-1-0 // 1000 --> 0-0-3-232
FutureIdea: create recursive function instead
*/
vector<int> JsonResponsePacketSerializer::length_to_dec_sequence(int size, int requiredBytes) throw()
{
	const int BITS_IN_BYTE = 8;
	int index = 0, divider = std::pow(2, BITS_IN_BYTE);
	vector<int> result;
	result.resize(requiredBytes);

	if (size > std::pow(2, (requiredBytes * BITS_IN_BYTE)))
	{
		throw std::exception("Number is to Big!");
	}
		
	
	while (size > 0)
	{
		result[requiredBytes - 1 - index] = size % divider;
		size = (int)(size / divider);
		index += 1;
	}

	return result;
}
	
