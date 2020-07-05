#pragma once

#include "Response.h"
#include "PlayerResults.h"
#include "LoggedUser.h"
#include <vector>
#include <map>;
#include "Game.h"

using std::vector;
using std::map;

class GetGameResultsResponse : Response
{
public:
	GetGameResultsResponse(int status, vector<PlayerResults> results);
	GetGameResultsResponse(int status, map<LoggedUser, GameData> results);

	virtual nlohmann::json castToJson() const;
	

protected:
	int _status;
	vector<PlayerResults> _results;
	
	string castResultsToString() const;
	void arrangeResults(map<LoggedUser, GameData> results);
};