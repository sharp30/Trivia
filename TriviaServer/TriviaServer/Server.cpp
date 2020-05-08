#include "Server.h"
#include <thread>
#include <string>
#include <iostream>

Server::Server()
{
	
}
//-----------constructor--------------
Server::Server(IDatabase& database)
{
	this->m_database = database;
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
