#pragma once

#include "Response.h"
#include "PlayerResults.h"
#include <vector>

using std::vector;

class GetGameResultsResponse : Response
{
public:
	GetGameResultsResponse(int status, vector<PlayerResults> results);
	//GetGameResultsResponse(int status, map<LoggedUser, GameData> results);
	virtual nlohmann::json castToJson() const;
	string castResultsToString() const;

protected:
	int _status;
	vector<PlayerResults> _results;
};