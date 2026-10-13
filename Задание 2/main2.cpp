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
	
	MyTime begin_air_time(10,00,00);
	MyTime end_air_time(13,00,00);
	
	cout << "Время промежутка: ";
	
	begin_air_time.info(); 
	cout << " - ";
	end_air_time.info();
	
	cout << endl << endl;
	
	MyTime test_time(10,00,00);
	
	cout << "Тестовое время для теста: ";
	test_time.info();
	cout << endl;
	
	cout << "Отнимем несколько секунд к тестовому таймеру... [+30]" << endl;
	test_time.substract_seconds(30);
	test_time.info();
	
	cout << endl;
	
	cout << "Вычитаем 10 часов в МИНУС (Тестовое время - Конечный промежуток): " << endl;
	test_time.substract_time(begin_air_time);
	test_time.info();
	
	cout << endl;
	
	cout << "Прибавим секунды к конечному промежутку... [+30]" << endl;
	test_time.add(30);
	test_time.info();
	
	cout << endl;
	cout << endl;
	
	cout << "=======================ЭЛЕКТРОННОЕ ТАБЛО АЭРОПОРТА=======================" << endl;
	while (file >> number_airline >> city >> h >> literal >> m)
	{
		MyTime air_time1;
		air_time1.hour = h;
		air_time1.minutes = m;
		
		air_time1.hour = h;
		air_time1.minutes = m;
		
		
		if (begin_air_time.to_seconds() <= air_time1.to_seconds() && end_air_time.to_seconds() >= air_time1.to_seconds())
		{
			
			cout << "Номер рейса: " << number_airline << " " << "Отправление В: " << city << endl;
			cout << "Время отправления: " << h << ":" << m << endl;
		}
		
		
		
		
		cout << endl;
	}
	
	file.close();
	return 0;
}
