#pragma once
#include "Message.h"

class ErrorResponse : Message
{
protected:
	string errorMessage;
};