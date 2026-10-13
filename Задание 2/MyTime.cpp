#include <iostream>
#include <iomanip>
#include "MyTime.h"
using namespace std;

MyTime::MyTime()
{
	hour = 0; minutes = 0; seconds = 0;
}

MyTime::MyTime(int _hour, int _minutes, int _seconds)
{
	hour = _hour; minutes = _minutes; seconds = _seconds;
}

void MyTime::info()
{
	
	if (hour < 10)
	{
		cout << setw(2) << setfill('0') << hour << ":";
	}
	else
	{
		cout << hour << ":";
	}
	
	if (minutes < 10)
	{
		cout << setw(2) << setfill('0') << minutes << ":";	
	}
	else
	{
		cout << minutes << ":";
	}
	
	if (seconds < 10)
	{
		cout << setw(2) << setfill('0') << seconds << endl;
	}
	else
	{
		cout << seconds << endl;
	}
	
	
}

inline int MyTime::to_seconds()
{
	int total = (hour * 3600) + (minutes * 60) + seconds;
	
	return (total % 86400 + 86400) % 86400; 
}

void MyTime::normalize()
{
	int total = to_seconds();
	
	if (total < 0)
	{
		total += 24 * 3600;
	}
	else
	{
		seconds = total % 60;
		minutes = (total / 60) % 60;
		hour = (total / 3600) % 24;
	}
	
}

MyTime MyTime::add(int seconds)
{
	this->seconds = this->seconds + seconds;
	return *this;
}

MyTime MyTime::add(MyTime time)
{
	hour = hour + time.hour;
	minutes = minutes + time.minutes;
	seconds = seconds + time.seconds;
	return *this;
}
