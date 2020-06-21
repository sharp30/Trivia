#pragma once

#include <vector>
#include <string>

#include "Response.h"

using std::string;
using std::vector;

class BestScoresResponse : public Response
{
public:

	BestScoresResponse(int status,vector<string> data);
	virtual json castToJson() const;
protected:
	vector<string> _data;
	int _status;
};