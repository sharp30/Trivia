#pragma once

const int NOT_FOUND = -1;
const int INFINITE = -8;

class Range
{
public:

    Range();
    Range(int start, int Len);
    void setStart(int val);
    void setEnd(int val);
    int getEnd()const;
    int getStart()const;
    int getDiff()const;
    bool operator>(Range other)const;
    bool operator<(Range other)const;
private:
    int _start;
    int _end;
};

