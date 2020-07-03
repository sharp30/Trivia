#pragma once

#include <string>
#include <vector>


using std::vector;
using std::string;

class Question
{
public:
	Question(string question, vector<string> answers);
	string getQuestion();
	vector<string> getPossibleQuestions();
	string getCorrectAnswer();
protected:
	string _question;
	vector<string> _possibleAnswers;


};