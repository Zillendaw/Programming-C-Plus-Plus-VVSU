#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle() : Figure()
{
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
	string name = getNameFile() + " Rectangle";
	setNameFile(name);
	saveToFile();
}

Rectangle::~Rectangle()
{
	
}

void Rectangle::saveToFile()
{
	ofstream file (getNameFile());
	
	if (!file.is_open())
	{
		cout << "ОШИБКА С ФАЙЛОМ ВОВРЕМЯ ЗАПИСИ! Программа закрывается...";
		exit(EXIT_FAILURE);
	}
	
	file << x1 << " ";
	file << x2 << " ";
	file << y1 << " ";
	file << y2 << " ";	
	
	file.close();
}

void Rectangle::loadFromFile()
{
	ifstream file (getNameFile());
	
	if (!file.is_open())
	{
		cout << "ФАЙЛ НЕ ОТКРЫЛСЯ! Программа закрывается...";
		exit(EXIT_FAILURE);
	}
	
	file >> x1;
	file >> x2;
	file >> y1;
	file >> y2;	
	
	file.close();
}

