#include "RequestResult.h"

RequestResult::RequestResult()
{
	this->_newHandler = nullptr;
	this->_success = false;
}

void RequestResult::setNewHandler(IRequestHandler* pointer)
{
	this->_success = true;
	this->_newHandler = pointer;
}
