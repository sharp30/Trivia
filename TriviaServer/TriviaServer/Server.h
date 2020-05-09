#pragma once

#include "Communicator.h"
#include "RequestHandlerFactory.h"
#include "IDataBase.h"

class Server
{
public:
	Server(IDatabase& database);
	void run();

protected:
	Communicator m_communicator;
	RequestHandlerFactory m_handlerFactory;
	IDatabase& m_database;
};