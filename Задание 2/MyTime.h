#ifndef MYTIME_H
#define MYTIME_H

class MyTime
{
public:
	int hour;
	int minutes;
	int seconds;
	MyTime();
	MyTime(int hour, int minutes, int seconds);
	void info();
	MyTime add(int seconds);
	MyTime add(MyTime time);
	void normalize();
	inline int to_seconds();
};

#endif // MYTIME_H

