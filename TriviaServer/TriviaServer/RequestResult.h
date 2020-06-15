#pragma once

#include <vector>

using std::vector;

class IRequestHandler;

typedef struct RequestResult
{
    RequestResult();
    void setNewHandler(IRequestHandler* pointer);
    vector<unsigned char> _buffer;
    IRequestHandler* _newHandler;
    bool _success;
}RequestResult;
