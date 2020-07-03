#pragma once

#include <string>
#include "json.hpp"

using std::string;

class SubmitAnswerRequest
{
public:
	SubmitAnswerRequest(nlohmann::json j);
	unsigned int getAnswerId();

protected:
	unsigned int _answerId;
};
