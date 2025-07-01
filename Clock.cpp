/* File: Clock.cpp
 * Course: CS215-001
 * Project: Lab 8
 * Purpose: Provide the delcaration of the class named Clock
 *			Note that it represents a 24-hour clock (or you can call it military time)
 * Author: Jayden Mcbride
 */
#include "Clock.h"
#include <iostream>
#include <iomanip>  // Make sure this is included

using namespace std;

// Default constructor
Clock::Clock()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}

// Alternative constructor
Clock::Clock(int hh, int mm, int ss) 
{
    setClock(hh, mm, ss);
}

// Set time to hh:mm:ss
void Clock::setClock(int hh, int mm, int ss)
{
    if (hh < 0 || hh >= HOURS_TO_WRAP || mm < 0 || mm >= HOUR_MIN_SEC || ss < 0 || ss >= HOUR_MIN_SEC)
    {
        cout << "Invalid time!" << endl;
        return;
    }
    hours = hh;
    minutes = mm;
    seconds = ss;
    adjustClock();
}

// Helper function to adjust time (e.g., overflow of seconds, minutes, hours)
void Clock::adjustClock()
{
    if (seconds >= HOUR_MIN_SEC)
    {
        minutes += seconds / HOUR_MIN_SEC;
        seconds = seconds % HOUR_MIN_SEC;
    }

    if (minutes >= HOUR_MIN_SEC)
    {
        hours += minutes / HOUR_MIN_SEC;
        minutes = minutes % HOUR_MIN_SEC;
    }

    if (hours >= HOURS_TO_WRAP)
    {
        hours = hours % HOURS_TO_WRAP;
    }
}

// Increase time by sec seconds
void Clock::incrementSeconds(int sec) 
{
    seconds += sec;
    adjustClock();
}

// Increase time by min minutes
void Clock::incrementMinutes(int min)
{
    minutes += min;
    adjustClock();
}

// Increase time by hh hours, wrap around to 0 if it exceeds 24 hours
void Clock::incrementHours(int hh)
{
    hours += hh;
    adjustClock(); //This helper function ensures that the time values are always valid
}

// Add C into the current clock time
void Clock::addTime(Clock C)
{
    hours += C.hours;
    minutes += C.minutes;
    seconds += C.seconds;
    adjustClock();
}

// Print time in hours:minutes:seconds in 24-hour format
void Clock::printTime() const
{
    cout << setw(2) << setfill('0') << hours << " : " //These are formatting manipulators used to display the time correctly.
        << setw(2) << setfill('0') << minutes << " : "
        << setw(2) << setfill('0') << seconds << endl;
}

// Compare with C: return -1 if earlier, 0 if same, 1 if later
int Clock::compareTime(Clock C) const 
{
    if (hours < C.hours || (hours == C.hours && minutes < C.minutes) || (hours == C.hours && minutes == C.minutes && seconds < C.seconds)) 
    {
        return -1;
    }
    else if (hours == C.hours && minutes == C.minutes && seconds == C.seconds) 
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}