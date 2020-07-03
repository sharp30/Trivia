#pragma once
#include <vector>
#include <map>

using std::vector;
using std::map;

class Game
{
public:
	Game();
	Question getQuestionForUser(LoggedUser user);
	void submitAnswer();
	void removePlayer();
protected:
	vector<Question> m_questions;
	map<LoggedUser, GameData> m_players;
};