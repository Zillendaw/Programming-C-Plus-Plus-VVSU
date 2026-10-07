#include <iostream>
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
	cout << hour << ":" << minutes << ":" << seconds << endl;
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
