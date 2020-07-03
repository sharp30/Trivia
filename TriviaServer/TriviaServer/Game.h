#pragma once
#include <vector>
#include <map>
#include "LoggedUser.h"
#include "Question.h"

using std::vector;
using std::map;



typedef struct GameData 
{
	int currentQuestion;
	unsigned int correctAnswerCount;
	unsigned int incorrectAnswerCount;
	unsigned int averangeAnswerTime;
} GameData;

class Game
{
public:
	Game(vector<Question> questions,vector<LoggedUser> players);
	Question getQuestionForUser(LoggedUser user) const;
	void submitAnswer(LoggedUser user,string answer);
	void removePlayer(LoggedUser) throw();
protected:
	vector<Question> m_questions;
	map<LoggedUser, GameData> m_players;
};

