#pragma once

#include <vector>

using std::vector;

class IRequestHandler;

typedef struct RequestResult
{
    RequestResult();
    vector<unsigned char> _buffer;
    IRequestHandler* _newHandler;
}RequestResult;