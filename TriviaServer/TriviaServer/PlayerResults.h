#pragma once
#include <string>

using std::string;

// a class that represents the results of a player in a single game
class PlayerResults
{
protected:
	string _username;
	unsigned int _correctAnswersCount;
	unsigned int _wrongAnswersCount;
	unsigned int _averageAnswerTime;

public:
	PlayerResults(string username, unsigned int correctAnswersCount, unsigned int wrongAnswersCount, unsigned int averageAnswerTime);

	void setUsername(string username);
	string getUsername() const;
	void setCorrectAnswersCount(unsigned int correctAnswersCount);
	unsigned int getCorrectAnswersCount() const;
	void setWrongAnswersCount(unsigned int wrongAnswersCount); 
	unsigned int getWrongAnswersCount() const;
	void setAverageAnswerTime(unsigned int averageAnswerTime);
	unsigned int getAverageAnswerTime() const;

	string toString() const;
};