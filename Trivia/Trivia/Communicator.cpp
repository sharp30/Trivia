#include "Communicator.h"
#include <exception>
#include <thread>
#include <string>
#include "LoginRequestHandler.h"
#pragma comment (lib, "ws2_32.lib")

// ----------------Constructor ----------------
Communicator::Communicator()
{
	_serverSocket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (_serverSocket == INVALID_SOCKET)
	{
		throw std::exception("Can't create Socket");
	}
}
/*
This function handles the communication with the clietns
Input:None
Output:None
*/
void Communicator::startHandleRequest()
{
	bindAndListen();

	while (true)
	{
		acceptClient();
	}
}
/*
This function binds the server socket to the requested port, and start listening
Input:None
Output:None
*/
void Communicator::bindAndListen()
{
	struct sockaddr_in sa = { 0 }; //initialize all memebers to 0
	sa.sin_port = htons(PORT);
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = 0;//IFACE

	if (::bind(this->_serverSocket, (struct sockaddr*) & sa, sizeof(sa)) == SOCKET_ERROR)
	{
		throw std::exception("Can't bind server socket");
	}

	if (::listen(this->_serverSocket, SOMAXCONN) == SOCKET_ERROR)
	{
		throw std::exception("Can't listens to clients' requests");
	}


}
/*
This function handles the conversation with the client
Input:clientSock -- The socket with the client
Output:None
*/
void Communicator::handleNewClient(SOCKET clientSock)
{
	char text[6];
		
	//send data to client
	if (send(clientSock, "HELLO", 5, 0) == INVALID_SOCKET)
	{
		throw std::exception("Can't send message to client :<");
	}
		
	//receive data from client
	int res = recv(clientSock, text, 5, 0);
		
	if (res == INVALID_SOCKET)
	{
		std::string s = "Error while recieving from socket: ";
		s += std::to_string(clientSock);
		throw std::exception(s.c_str());
	}
	text[5] = '\0';

	std::cout << text;
}

/*
This funtion wait until a client connects and acccepts it
Input:None
Output:None
*/
void Communicator::acceptClient()
{
	SOCKET clientSocket = accept(this->_serverSocket, NULL, NULL); //wait until client arrives and accepts it.
	if (clientSocket == INVALID_SOCKET)
	{
		throw std::exception("Can't accept client");
	}
	//insert to clients list
	LoginRequestHandler login;
	this->_mClients.insert(std::pair<SOCKET, IRequestHandler*>(clientSocket, (IRequestHandler*)&login));

	//call to managing thread
	std::thread clientThread(&Communicator::handleNewClient, this, clientSocket);
	clientThread.detach();

}
