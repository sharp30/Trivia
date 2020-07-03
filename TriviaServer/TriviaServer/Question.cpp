#include "Question.h"

Question::Question(string question, vector<string> answers, unsigned int correct)
{
	this->_question = question;
	this->_possibleAnswers = answers;
	this->_correctIndex = correct;
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
	return this->_possibleAnswers[_correctIndex];
}
