#include "Server.h"
#include <thread>
#include <string>
#include <iostream>

/*
This function manages the server running
Input:None
Output:None
*/
void Server::run()
{
	const std::string END = "EXIT";
	std::thread tCommunicator(&Communicator::startHandleRequest, &this->m_communicator);
	tCommunicator.detach();
	std::string inp;
	while (inp != "EXIT")
	{
		std::cin >> inp;
	}
	std::cout << "finished";
}
