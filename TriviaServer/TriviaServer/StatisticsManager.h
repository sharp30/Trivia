#pragma once
#include "IDatabase.h"
#include <vector>
#include "map"
using std::map;
using std::vector;

class StatisticsManager
{
public:
	StatisticsManager() = default;
	StatisticsManager(IDatabase* database);
	map<string,string> getStatistics(string username) throw();
	vector<string> getBestPlayers() throw();

private:
	IDatabase* m_database;
};