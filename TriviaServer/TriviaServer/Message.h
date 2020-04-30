#pragma once

#include <string>
#include "json.hpp"

using std::string;
using nlohmann::json;

class Message
{
public:
	virtual json castToJson() const = 0;
};
