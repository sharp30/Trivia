#include "RequestInfo.h"


//------------------constructor--------------------

RequestInfo::RequestInfo(int id, char* buff, int size)
{
	this->_id = id;
	this->_receivalTime =std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());// the time now
	this->_buffer = std::vector<unsigned char>(buff, buff + size); // from char* to vector<unsigned char>
}

/*
This function returns the Id value
Input:None
Output:the id of the request
*/
int RequestInfo::getId()
{
	return _id;
}


/*
This function returns time of the request
Input:None
Output:the time of the request
*/
time_t RequestInfo::getTime()
{
	return _receivalTime;
}


/*
This function returns the buffer
Input:None
Output:the data part of the request
*/
vector<unsigned char> RequestInfo::getBuffer()
{
	return this->_buffer;
}
