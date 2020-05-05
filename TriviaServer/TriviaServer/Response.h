#pragma once

#include <string>
#include "json.hpp"

using std::string;
using nlohmann::json;

class Response
{
public:
	virtual json castToJson() const = 0;
	int getMsgCode() const;

protected:
	int messageCode;
};