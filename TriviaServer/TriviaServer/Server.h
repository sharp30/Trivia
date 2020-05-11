#pragma once

#include "Communicator.h"
#include "RequestHandlerFactory.h"
#include "IDataBase.h"

class Server
{
public:
	static Server* CreateServer(IDatabase& database);
	void run();
	~Server();
protected:
	Communicator m_communicator;
	RequestHandlerFactory m_handlerFactory;
	IDatabase& m_database;

private:
	Server(IDatabase& database);
	
	static Server* s_m_server; // static-member

};