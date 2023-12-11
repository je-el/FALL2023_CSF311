//timeofday.hpp
//Jewel Maldonado
//2023-9-1
//Header for class TimeOfDay
//DRY principle => dont repeat yourself

#ifndef_FILE_TIMEOFDAY_HPP_INCLUDED
#define_FILE_TIMEOFDAY_HPP_INCLUDED

#include <ostream>
//For std::ostream

class TimeOfDay {
public:
    // Default Ctor
    TimeOfDay()
        : secs(0)
    {}

    //ctor from hrs, mins, secs
    TimeOfDay(int hh, int mm, int ss)
    {}
    //pre-incremeent
    TimeOfDay & operator++()
    {
        ++secs;
        secs %= 60*60*24;
        return *this;
    }
    //post-increment
    TimeOfDay operator++(int dummy)
    {
        auto prev(*this);
        ++(*this);
        return prev;
    }
    //pre-decrement
    TimeOfDay & operator--()
    {}
    //post-decrement
    TimeOfDay operator--(int dummy)
    {}

    void getTime(int & hh, int & mm, int & ss)
    {}
    void setTime(int hh, int mm, int ss)
    {}

private:
    int _hh; //hours past midnight 0...
    int _mm; //minutes past the hour 0..59
    int _ss; //seconds past the minute 0..59

}; // end of class

std::ostream & operator<<(std::ostream & out,const TimeOfDay & t){}

#endif
