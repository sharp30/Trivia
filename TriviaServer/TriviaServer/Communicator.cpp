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
	const int ID_SIZE = 1; // number of bytes the ID takes
	const int SIZE_LENGTH = 4; // number of bytes the content's size takes

	char code[ID_SIZE];
	char size[SIZE_LENGTH];
	char* content = nullptr;
	int sizeInt = 0;
	
	// a one timed message to client
	if (send(clientSock, "HELLO", 5, 0) == INVALID_SOCKET)
	{
		throw std::exception("Can't send message to client :<");
	}

	while (true) // TODO: in the next version, run untill a logout request appears
	{
		//receive data from client
		int res = recv(clientSock, code, ID_SIZE, 0);

		res = recv(clientSock, size, SIZE_LENGTH, 0);

		content = new char[convertBinaryToInt(size, SIZE_LENGTH)];
		res = recv(clientSock, content, convertBinaryToInt(size, SIZE_LENGTH), 0);

		//TODO: continue from this point, add operations and return respone to client

		if (res == INVALID_SOCKET)
		{
			std::string s = "Error while recieving from socket: ";
			s += std::to_string(clientSock);
			throw std::exception(s.c_str());
			delete content;
		}
	}

	delete content;
	
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

/*
TODO: add documantation
*/
int Communicator::convertBinaryToInt(char* str, int size)
{
	//#TODO: make this function do the following
	//input: "ab(4" / [00101101, 01010011, 11001010, 00001101]
	//output: an integer represents the value of the binary sequence

	//#TODO: think about a better place for this function
	return 0;
}

/*
TODO: add documantation
*/
vector<unsigned char> Communicator::convertDetailsToVector(char* code, char* size, char* content)
{
	return vector<unsigned char>();
}
