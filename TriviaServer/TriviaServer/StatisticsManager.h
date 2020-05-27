#pragma once
#include "IDatabase.h"
#include <vector>
#include "LoggedUser.h"

using std::vector;

class StatisticsManager
{
public:
	StatisticsManager() = default;
	StatisticsManager(IDatabase* database);
	void getStatistics() throw();
	void signup(string username, string password, string email) throw();

private:
	IDatabase* m_database;
};