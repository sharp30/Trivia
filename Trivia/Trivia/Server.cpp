#include "Server.h"
#include <thread>
#include <string>
#include <iostream>

void Seerver::run()
{
	std::thread tCommunicator(&Communicator::startHandleRequest, &this->m_communicator);

	std::string inp;
	//while(std::cin.read()!= "EXIT")
}
