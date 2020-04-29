#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <map>

#include "IRequestHandler.h"

using std::map;

class Communicator
{
public:

protected:
	map<SOCKET, IRequestHandler*> m_clients;
};