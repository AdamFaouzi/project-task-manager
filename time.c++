#include <iostream> //import the input output operations for C++
#include <vector>   //for dynamic array size
#include <algorithm>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

class Time
{        // initialise the Time class
private: // outline the private attributes of the Time class
    int year;
    int month;
    int day;
    double time;

public: // outline the public functions of the Time class
    Time()
    {
    }
    Time(int y, int m, int d, double t)
    { // all arguments constructor function
        year = y;
        month = m;
        day = d;
        time = t;
    }
    // getters functions
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    int getTime() { return time; }
    // setters functions
    void setYear(int y) { year = y; }
    void setMonth(int m) { month = m; }
    void setDay(int d) { day = d; }
    void setTime(double t) { time = t; }

    friend ostream &operator<<(ostream &os, const Time &t)
    {
        os << t.month << "/" << t.day << "/" << t.year << " at: " << t.time << endl;
        return os;
    }
};
