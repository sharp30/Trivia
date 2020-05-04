#include "RequestInfo.h"


//------------------constructors--------------------
RequestInfo::RequestInfo(int id, time_t time, vector<unsigned char> buff)
{
	this->_id = id;
	this->_receivalTime = time;
	this->_buffer = buff;
}

RequestInfo::RequestInfo(int id, char* buff, int size)
{
	this->_id = id;
	this->_receivalTime =std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());// the time now
	for (int i = 0; i < size; i++)
	{
		this->_buffer.push_back(buff[i]);
	}
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
