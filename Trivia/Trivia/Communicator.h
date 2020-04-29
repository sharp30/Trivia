#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <map>

#include "IRequestHandler.h"
#include "WSAInitializer.h"

const int PORT = 2020;
using std::map;

class Communicator
{
public:
	Communicator();
	void startHandleRequest();
protected:
	void bindAndListen();
	void handleNewClient(SOCKET clientSock);
	void acceptClient();
	map<SOCKET, IRequestHandler*> m_clients; 
	SOCKET _serverSocket; //the listening socket

private:
	WSAInitializer _wsa;
};