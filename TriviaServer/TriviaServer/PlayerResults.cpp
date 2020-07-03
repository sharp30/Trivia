#include "PlayerResults.h"

PlayerResults::PlayerResults(string username, unsigned int correctAnswersCount, unsigned int wrongAnswersCount, unsigned int averageAnswerTime)
{
	this->_username = username;
	this->_correctAnswersCount = correctAnswersCount;
	this->_wrongAnswersCount = wrongAnswersCount;
	this->_averageAnswerTime = averageAnswerTime;
}

//setters & getters 
void PlayerResults::setUsername(string username) { this->_username = username; }
string PlayerResults::getUsername() const { return this->_username; }
void PlayerResults::setCorrectAnswersCount(unsigned int correctAnswersCount) { this->_correctAnswersCount = correctAnswersCount; }
unsigned int PlayerResults::getCorrectAnswersCount() const { return this->_correctAnswersCount; }
void PlayerResults::setWrongAnswersCount(unsigned int wrongAnswersCount) { this->_wrongAnswersCount = wrongAnswersCount; }
unsigned int PlayerResults::getWrongAnswersCount() const { return this->_wrongAnswersCount; }
void PlayerResults::setAverageAnswerTime(unsigned int averageAnswerTime) { this->_averageAnswerTime = _averageAnswerTime; }
unsigned int PlayerResults::getAverageAnswerTime() const { return this->_averageAnswerTime; }

/*
the function will cast the object to a string in this template: [username:correctAnswersCount:wrongAnswersCount:averageTime]
input: none
output: string represents the object
example: [moshe:5:6:10]
*/
string PlayerResults::toString() const
{
	string txt = "[";

	txt += this->_username + ":";
	txt += this->_correctAnswersCount + ":";
	txt += this->_wrongAnswersCount + ":";
	txt += this->_averageAnswerTime + "]";

	return txt;
}
