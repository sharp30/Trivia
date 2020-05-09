#include "Server.h"
#include "SqliteDataBase.h"
int main()
{
	SqliteDataBase data;
	Server server((IDatabase&)data);

	server.run();

	return 0;
}