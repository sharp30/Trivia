#pragma once
#include "IDatabase.h"
#include <vector>

using std::vector;

class StatisticsManager
{
public:
	StatisticsManager() = default;
	StatisticsManager(IDatabase* database);
	vector<string> getStatistics(string username) throw();

private:
	IDatabase* m_database;
};