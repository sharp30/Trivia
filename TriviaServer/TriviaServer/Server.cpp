#include "Server.h"
#include <thread>
#include <string>
#include <iostream>

Server* Server::s_m_server = nullptr;

//-----------constructor--------------
Server::Server(IDatabase& database) :m_handlerFactory(&database),m_communicator(&this->m_handlerFactory),m_database(database){}	

Server* Server::CreateServer(IDatabase& database)
{
	if (s_m_server == 0) // check whether a server already exists
	{
		s_m_server = new Server(database);
	}

	return s_m_server;
}

/*
This function manages the server running
Input:None
Output:None
*/
void Server::run()
{
	std::thread tCommunicator(&Communicator::startHandleRequest, &this->m_communicator);
	tCommunicator.detach();

	const std::string END = "EXIT";
	std::string inp;
	while (inp != END)
	{
		std::cin >> inp;
	}
	std::cout << "finished";

}

Server::~Server()
{
	if (s_m_server != nullptr)
	{
		delete s_m_server;
	}
}
