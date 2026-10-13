#include <iostream>
#include <iomanip>
#include "MyTime.h"
using namespace std;

MyTime::MyTime()
{
	hour = 0; minutes = 0; seconds = 0;
	normalize();
}

MyTime::MyTime(int _hour, int _minutes, int _seconds)
{
	hour = _hour; minutes = _minutes; seconds = _seconds;
	normalize();
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

void MyTime::substract_seconds(int seconds_to_substract)
{
	int total = to_seconds() - seconds_to_substract;
	
	// Обновляем поля используя метод normalize()
	hour = 0;
	minutes = 0;
	seconds = total;
	normalize();
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

	seconds = total % 60;
	minutes = (total / 60) % 60;
	hour = (total / 3600) % 24;
		
}

MyTime MyTime::add(int seconds)
{
	this->seconds = this->seconds + seconds;
	
	normalize();
	return *this;
}

MyTime MyTime::add(MyTime time)
{
	hour = hour + time.hour;
	minutes = minutes + time.minutes;
	seconds = seconds + time.seconds;
	
	normalize();
	return *this;
}


MyTime MyTime::substract_time(MyTime& other)
{
	// Вычитаем секунды второго объекта из текущего объекта
	substract_seconds(other.to_seconds());
	
	return *this;
}
