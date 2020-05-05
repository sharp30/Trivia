#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
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
	map<SOCKET, IRequestHandler*> _mClients; 
	SOCKET _serverSocket; //the listening socket

private:

	static int convertBinaryToInt(char* str, int size);
	static vector<unsigned char> convertDetailsToVector(char* code, char* size, char* content);
	WSAInitializer _wsa;
};