#include "Server.h"
#include <thread>
#include <string>
#include <iostream>
/*Server::Server()
{
	
}*/
//-----------constructor--------------
Server::Server(IDatabase& database) :m_handlerFactory(&database),m_communicator(&this->m_handlerFactory),m_database(database)
{
	//this->m_database = database;
	//this->m_communicator(&this->m_handlerFactory);
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
