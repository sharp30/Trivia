#include "GetStatisticsResponse.h"

//------------constructor----------------
GetStatisticsResponse::GetStatisticsResponse(int _status, std::map<string,string> data)
{
	this->status = _status;
	this->messageCode = 71;
	this->statistics = data;
}

/*
The function will cast a signup response to JSON format
input: none
output: json format of this object
*/
json GetStatisticsResponse::castToJson() const
{
	return json{ {"status",this->status},
		{"gamesAmount",this->statistics.at("gamesAmount")},
		{"correctAnswers",this->statistics.at("correctAnswers")},
		{"incorrectAnswers",this->statistics.at("incorrectAnswers")},
		{"averageAnswerTime",this->statistics.at("averageAnswerTime")} };

}

/*
string GetStatisticsResponse::castStatisticsToString() const
{
	string str = "";

	vector<string> temp = this->statistics;

	for (vector<string>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		str += *it;
		str += ", ";
	}

	return str.substr(0, str.length() - 2);
}
*/