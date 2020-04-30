#pragma once

#include "Message.h"

class LoginResponse : Message
{
protected:
	unsigned int status;
};