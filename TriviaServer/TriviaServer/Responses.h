#pragma once

#include <string>
#include "json.hpp"

using std::string;
using nlohmann::json;

namespace Responses
{
	struct Response { } typedef Response; // base class - maybe useless

	struct ErrorResponse : Response
	{
		string message;
	} typedef ErrorResponse;

	struct LoginResponse : Response
	{
		unsigned int status;
	} typedef LoginResponse;

	struct SignupResponse : Response
	{
		unsigned int status;
	} typedef SignupResponse;

	//------temp functions to convert json to response, vice versa--------
	void to_json(json& j, const ErrorResponse& response)
	{
		j = json{ {"message", response.message} };
	}

	void from_json(const json& j, ErrorResponse& response) 
	{
		j.at("message").get_to(response.message);
	}

	void to_json(json& j, const LoginResponse& response)
	{
		j = json{ {"status", response.status} };
	}

	void from_json(const json& j, LoginResponse& response) 
	{
		j.at("status").get_to(response.status);
	}

	void to_json(json& j, const SignupResponse& response)
	{
		j = json{ {"status", response.status} };
	}

	void from_json(const json& j, SignupResponse& response) 
	{
		j.at("status").get_to(response.status);
	}
	//-----------------------------------------------------------------
}