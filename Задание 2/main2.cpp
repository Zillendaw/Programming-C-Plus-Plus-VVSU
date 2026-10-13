#include <iostream>
#include <fstream>
#include "MyTime.h"
using namespace std;

int main()
{
	ifstream file ("flights.txt");
	
	if (!file.is_open())
	{
		cout << "ФАЙЛ НЕ ОТКРЫЛСЯ! Программа закрывается...";
		return -1;
	}
	
	int h,m,s;
	string number_airline, city;
	string str_buffer;
	char literal = ':';
	
	int i = 1;
	
	MyTime begin_air_time(11,00,00);
	MyTime end_air_time(13,00,00);
	
	int begin_time = begin_air_time.to_seconds();
	int end_time = end_air_time.to_seconds();
	
	cout << "Время промежутка: ";
	
	begin_air_time.info(); 
	cout << " - ";
	end_air_time.info();
	
	cout << endl << endl;
	
	while (file >> number_airline >> city >> h >> literal >> m)
	{
		MyTime air_time1;
		air_time1.hour = h;
		air_time1.minutes = m;
		
		air_time1.hour = h;
		air_time1.minutes = m;
		
		if (begin_air_time.to_seconds() < air_time1.to_seconds() && end_air_time.to_seconds() > air_time1.to_seconds())
		{
			
			cout << "Номер рейса: " << number_airline << " " << "Отправление В: " << city << endl;
			cout << "Время отправления: " << h << ":" << m << endl;
			air_time1.info();
			
		}
		
		
		cout << endl;
	}
	
	file.close();
	return 0;
}
