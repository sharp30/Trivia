#include "Communicator.h"
#include <exception>
#include <thread>
#include <string>
#include "LoginRequestHandler.h"
#pragma comment (lib, "ws2_32.lib")
#include "RequestInfo.h"

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

	char id[ID_SIZE];
	char size[SIZE_LENGTH];
	char* reqContent = nullptr;
	int sizeInt = 0;
	int idInt = 0;
	
	map<SOCKET, IRequestHandler*>::iterator client = this->_mClients.find(clientSock); // iterartor for place in comunicator map
	if (client == this->_mClients.end())
	{
		std::string s = "Error was occurred";
		s += std::to_string(clientSock);
		throw std::exception(s.c_str());
	}


	// a one timed message to client
	if (send(clientSock, "HELLO", 5, 0) == INVALID_SOCKET)
	{
		throw std::exception("Can't send message to client :<");
	}

	while (true) // TODO: in the next version, run untill a logout request appears
	{
		//receive data from client
		//TOOD:recieve utils function + check validation
		int res = recv(clientSock, id, ID_SIZE, 0);
		
		idInt = convertBinaryToInt(id,ID_SIZE);

		res = recv(clientSock, size, SIZE_LENGTH, 0);
		
	    sizeInt = convertBinaryToInt(size,SIZE_LENGTH);

		reqContent = new char[convertBinaryToInt(size, SIZE_LENGTH)]; // have to be deleted
		res = recv(clientSock, reqContent, convertBinaryToInt(size, SIZE_LENGTH), 0);

		if (res == INVALID_SOCKET)
		{
			std::string s = "Error while recieving from socket: ";
			s += std::to_string(clientSock);
			throw std::exception(s.c_str());
			delete reqContent;
		}

		RequestInfo req(idInt, reqContent,sizeInt);
		delete reqContent;
		reqContent = nullptr;

		//TODO: continue from this point, add operations and return respone to client
		if (client->second->isRequestRelevant(req))
		{
			RequestResult reqResult = client->second->handleRequest(req);

			//change RequestHandler
			delete client->second;
			client->second = reqResult._newHandler;

			//send response to cl
			char* response = (char*)&(*reqResult._buffer.begin());//from vector<unsigned char> to char *
			res = send(clientSock, response, reqResult._buffer.size(), 0);
		}
	}

	//delete reqContent;
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
	this->_mClients.insert(std::pair<SOCKET, IRequestHandler*>(clientSocket, (IRequestHandler*)new LoginRequestHandler()));

	//call to managing thread
	std::thread clientThread(&Communicator::handleNewClient, this, clientSocket);
	clientThread.detach();

}
/*
This function converts from binary to integer value
For Example:0111 ==> 7
Input : bin - vector of chars: the value in binary
Output:The integer value
*/
int Communicator::convertBinaryToInt(char* buff,int size)
{
	const int COUNTING_BASE = 2; //The binary base ==> 2
	int val = 0;

	for (int i = 0; i < size; i++)
	{
		int bit = buff[i];
		val += pow(2, size - i - 1) * bit;
	}

	return val;
}


/*
TODO: add documantation
*/
vector<unsigned char> Communicator::convertDetailsToVector(char* code, char* size, char* content)
{
	return vector<unsigned char>();
}
