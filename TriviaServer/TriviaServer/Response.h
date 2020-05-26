#pragma once

#include <string>
#include "Json.hpp"

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
