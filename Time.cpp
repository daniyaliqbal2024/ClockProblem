#include "Time.h"
#include <string>
using namespace std;


// Ignore this constructor
Time::Time()
{
	hours   = 0;
	minutes = 0;
	seconds = 0;
}

// Ignore this constructor
Time::Time(int hours, int minutes, int seconds)
{
	this->hours   = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

// .......................................Tasks Below...................

/**
 * Task 1:
 * Add one second to the current time.
 * When the seconds value reaches 60, it rolls over to zero.
 * When the seconds roll over to zero, the minutes advance.
 * So 00:00:59 rolls over to 00:01:00.
 * When the minutes reach 60, they roll over and the hours advance.
 * So 00:59:59 rolls over to 01:00:00.
 * When the hours reach 24, they roll over to zero.
 * So 23:59:59 rolls over to 00:00:00.
 */
void Time::advanceOneSecond()
{
	{
		        seconds = seconds + 1;
		        if (seconds>=60)
		        {
		            seconds = 00;
		            minutes= minutes + 1;
		        }
		        if (minutes>=60)
		        {
		            minutes= 00;
		            hours= hours+1;
		        }
		        if (hours>= 24)
		        {
		            hours = 00;
		        }
		    }
}


/**
 * Task 2:
 * Compare this time to otherTime.
 * Assumes that both times are in the same day.
 * Returns -1 if this Time is before otherTime.
 * Returns 0 if this Time is the same as otherTime.
 * Returns 1 if this Time is after otherTime.
 */
int Time::compareTo(Time otherTime)
{
	if  (hours < otherTime.hours )
	        {
	           return -1;
	        }
	        if ( hours==otherTime.hours && minutes < otherTime.minutes)
	        {
	            return -1;
	        }
	        if ( hours==otherTime.hours && minutes == otherTime.minutes && seconds < otherTime.seconds)
	        {
	            return -1;
	        }

	        if (hours > otherTime.hours)
	        {
	            return 1;
	        }

	        if ( hours==otherTime.hours && minutes > otherTime.minutes)
	        {
	            return 1;
	        }
	        if ( hours==otherTime.hours && minutes == otherTime.minutes && seconds > otherTime.seconds)
	        {
	            return 1;
	        }

	        else return 0;
}

/**
 * Task 3:
 * Add an offset to this Time.
 * Rolls over the hours, minutes and seconds fields when needed.
 */
void Time::add(Time otherTime)
{
        seconds = seconds + otherTime.seconds;
        if (seconds >= 60)
        {
            minutes= minutes + 1;
            seconds = seconds - 60;

        }


        minutes = minutes + otherTime.minutes;

        if (minutes >= 60)
        {

            hours= hours+1;
            minutes=  minutes -60;
        }

        hours = hours + otherTime.hours;
        if (hours >= 24)
        {
            hours= hours - 24;
        }
 }

/**
 * Task 4:
 * Subtract an offset from this Time.
 * Rolls over (under?) the hours, minutes and seconds fields when needed.
 */
void Time::subtract(Time otherTime)
{
        seconds = seconds - otherTime.seconds;
        if (seconds < 00)
        {
            seconds = seconds + 60 ;
            minutes= minutes - 1;
        }


        minutes = minutes - otherTime.minutes;

        if (minutes < 00)
        {
            minutes = minutes + 60;
            hours= hours - 1;
        }

        hours = hours - otherTime.hours;
        if (hours < 00)
        {
            hours= hours + 24;
        }

    }
// .......................................WORK COMPLETED...................

// Ignore this method, it is used to print out the Time value
string pad(int value)
{
    string sign = "";
    if (value < 0)
    {
        sign = "-";
        value = -value;
    }

    if (value < 10) {
        return sign + "0" + std::to_string(value);
    }
    else {
        return sign + std::to_string(value);
    }
}

// You can ignore this as it is only used to print the Time object
std::ostream& operator<<(std::ostream& stream, const Time& t)
{
    return stream << pad(t.hours) << ":" << pad(t.minutes) << ":" << pad(t.seconds);
}
