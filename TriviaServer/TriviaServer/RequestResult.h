#pragma once
#include "IRequestHandler.h"
#include <vector>
using std::vector;

typedef struct RequestResult
{
    vector<unsigned char> _buffer;
    IRequestHandler* _newHandler;
}RequestResult;