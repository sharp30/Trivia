#include "BestScoresResponse.h"

BestScoresResponse::BestScoresResponse(int status,vector<string> data)
{
	this->messageCode = 75;
	this->_status = status;
	this->_data = data;
}

/*
The function will cast a BestScore response to JSON format
input: none
output: json format of this object
*/
json BestScoresResponse::castToJson() const
{
	//build answer
	string txt = "";
	for (size_t i = 0; i < _data.size(); i++)
	{
		txt += _data[i];
		if (i + 1 < _data.size()) //if not the last
			txt += ',';
	}
	return json{ {"UserStatistics" , txt} };
}
