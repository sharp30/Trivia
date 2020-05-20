#include "Range.h"
// ------------ constructors ------------
Range::Range()
{
    this->_start = 0;
    this->_end = INFINITE;
}

Range::Range(int start,int end)
{
    this->_start =start;
    this->_end= end;
}

//---------setters -----------------
void Range::setStart(int val)
{
    this->_start = val;
}
void Range::setEnd(int val)
{
    this->_end = val;
}

//-------------------- getters -------------------------
int Range::getStart() const
{
    return this->_start;
}

int Range::getEnd() const
{
    return this->_end;
}

bool Range::operator>(Range other) const
{
    return this->_start > other._start;
}

bool Range::operator<(Range other) const
{
    return !(*this > other);
}

//return the difference between the the end and start
int Range::getDiff()const
{
    if (this->_end == INFINITE)
        return INFINITE;
    return  this->_end - this->_start +1;
}
