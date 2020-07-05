#include "GetGameResultsResponse.h"

GetGameResultsResponse::GetGameResultsResponse(int status, vector<PlayerResults> results)
{
	this->messageCode = 84;
	this->_status = status;
	this->_results = results;
}


GetGameResultsResponse::GetGameResultsResponse(int status, map<LoggedUser, GameData> results)
{
	this->messageCode = 84;
	this->_status = status;
	arrangeResults(results);
}


nlohmann::json GetGameResultsResponse::castToJson() const
{
	return nlohmann::json{ {"status" , _status}, {"results", castResultsToString()} };
}

/*
the function will format the results: "[result1],[result2],[result3]"
input: none
output: a string represents the results
*/
string GetGameResultsResponse::castResultsToString() const
{
	string txt = "";
	for (int i = 0; i < this->_results.size(); i++)
	{
		txt += this->_results[i].toString() + ",";
	}
	return txt.substr(0, txt.size() - 1);
}


void GetGameResultsResponse::arrangeResults(map<LoggedUser, GameData> results)
{
	vector<PlayerResults> res;
	
	for (map<LoggedUser, GameData>::iterator it = results.begin(); it != results.end(); it++)
	{
		PlayerResults pr(it->first.getUsername(), it->second);
		res.push_back(pr);
	}

	this->_results = res;
}
