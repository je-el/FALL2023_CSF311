// timeofday.hpp  UNFINISHED
// Glenn G. Chappell
// 2023-09-01
//
// For CS 311 Fall 2023
// Header for class TimeOfDay
// Time of day: hours, minutes, seconds

#ifndef FILE_TIMEOFDAY_HPP_INCLUDED
#define FILE_TIMEOFDAY_HPP_INCLUDED

#include <ostream>
// For std::ostream


// *********************************************************************
// class TimeOfDay - Class definition
// *********************************************************************


// class TimeOfDay
// Time of day: hours, minutes, seconds.
class TimeOfDay {

// ***** TimeOfDay: Ctors, dctor, op= *****
public:

    // Default ctor
    // Set time to midnight.
    TimeOfDay()
        :_secs(0)
    {}

    // Ctor from hours, minutes, seconds
    // Set time to given # of hours, minutes, seconds past midnight.
    TimeOfDay(int hh,
              int mm,
              int ss)
    {
        // TODO: WRITE THIS!!!
    }

// ***** TimeOfDay: General public operators *****
public:

    // op++ [pre]
    // Move time one second forward.
    TimeOfDay & operator++()
    {
        ++_secs;
        _secs %= 24*60*60;
        return *this;
    }

    // op++ [post]
    // Move time one second forward.
    TimeOfDay operator++([[maybe_unused]] int dummy)
    {
        auto save = *this;
        ++(*this);
        return save;
    }

    // op-- [pre]
    // Move time one second backward.
    TimeOfDay & operator--()
    {
        --_secs;
        if (_secs == -1)
            _secs = 24*60*60-1;
        return *this;
    }

    // op-- [post]
    // Move time one second backward.
    TimeOfDay operator--([[maybe_unused]] int dummy)
    {
        auto save = *this;
        --(*this);
        return save;
    }

// ***** TimeOfDay: General public functions *****
public:

    // getTime
    // Return hours, minutes, seconds in reference parameters.
    void getTime(int & hh,
                 int & mm,
                 int & ss) const
    {
        // TODO: WRITE THIS!!!
    }

    // setTime
    // Set time to given # of hours, minutes, seconds past midnight.
    void setTime(int hh,
                 int mm,
                 int ss)
    {
        // TODO: WRITE THIS!!!
    }

// ***** TimeOfDay: Data members *****
private:

    int _secs;  // Seconds past midnight (range 0 .. 24*60*60-1)

};  // End class TimeOfDay


// *********************************************************************
// class TimeOfDay - Declarations of associated global operators
// *********************************************************************


// operator<< (ostream,TimeOfDay)
// Prints given TimeOfDay object as "hh:mm:ss", with hh padded on the
// left with blanks, and mm, ss padded on the left with zeroes.
// Function defined in source file.
std::ostream & operator<<(std::ostream & out,
                          const TimeOfDay & t);


#endif  //#ifndef FILE_TIMEOFDAY_HPP_INCLUDED

