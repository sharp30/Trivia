#include "Question.h"

Question::Question(string question, vector<string> answers)
{
	this->_question = question;
	this->_possibleAnswers = answers;
}

string Question::getQuestion()
{
	return this->_question;
}

vector<string> Question::getPossibleQuestions()
{
	return this->_possibleAnswers;
}

string Question::getCorrectAnswer()
{
	return this->_possibleAnswers[this->_possibleAnswers.size()-1];//place -> 3
}
