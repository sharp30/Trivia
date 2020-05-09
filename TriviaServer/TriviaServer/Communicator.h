#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <map>

#include "IRequestHandler.h"
#include "WSAInitializer.h"
#include "RequestHandlerFactory.h"

const int PORT = 2020;
using std::map;

class Communicator
{
public:
	Communicator(RequestHandlerFactory* factory);
	void startHandleRequest();
protected:
	void bindAndListen();
	void handleNewClient(SOCKET clientSock);
	void acceptClient();
	map<SOCKET, IRequestHandler*> _mClients; 
	SOCKET _serverSocket; //the listening socket
	RequestHandlerFactory* m_handlerFactory;

private:
	WSAInitializer _wsa;
};