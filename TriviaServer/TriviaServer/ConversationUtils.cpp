#include "ConversationUtils.h"

/*
This function gets input of length bytes from the socket
Input:sock: The socket with the client
	  buff -> pointer to the dest buffer
	  length ->num of bytes to read
Output:None
*/
void ConversationUtils::receiveFromSocket(SOCKET sock, char* buff, int length) throw()
{
	int	res = recv(sock, buff,length, 0);
	if (res == INVALID_SOCKET)
	{
		std::string s = "Error while recieving from socket: ";
		s += std::to_string(sock);
		throw std::exception(s.c_str());
	}
}

/*
This function casts bson to json object
Input:buff -> bson as binary buff
Output:json object
*/
json ConversationUtils::castBinToJson(vector<unsigned char> buff)
{
	return json::from_bson(buff);
}


/*
This function casts json to bson as binary buffer
Input:j -> json object
Output:binary buffer
*/
vector<unsigned char> ConversationUtils::castJsonToBin(json j)
{
	return json::to_bson(j);
}

/*
This function converts from binary to integer value
For Example:0111 ==> 7
Input : bin - vector of chars: the value in binary
Output:The integer value
*/
int ConversationUtils::castBinToInt(vector<unsigned char> bin)
{
	const int COUNTING_BASE = 2; //The binary base ==> 2
	int val = 0;
	int size = bin.size();

	for (int i = 0; i < size; i++)
	{
		int bit = bin[i];
		val += pow(COUNTING_BASE, size - i - 1) * bit;
	}
	return val;
}
/*
This function casts char* of to vector of unsigned chars
Input:buff -> the buffer as char*
	  size -> the size of the buffer
Output:vector of bytes
*/
vector<unsigned char> ConversationUtils::castBuffToVector(char* buff, int size)
{
	return std::vector<unsigned char>(buff, buff + size);
}

vector<unsigned char> ConversationUtils::castIntToBin(int value)
{
	return vector<unsigned char>();
}
