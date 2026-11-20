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

Rectangle::Rectangle(int input_x1, int input_x2, int input_y1, int input_y2) : Figure()
{
	x1 = input_x1;
	x2 = input_x2;
	y1 = input_y1;
	y2 = input_y2;
	string name = getNameFile() + " Rectangle";
	setNameFile(name);
	saveToFile();
}

Rectangle::~Rectangle()
{
	cout << "Удаляем файл с диска..." << endl;
	
	// std::remove принимает const char*, поэтому вызываем .c_str()
	if (remove(getNameFile().c_str()) == 0)
	{
		cout << "Файл успешно удалён." << endl;
	}
	else
	{
		perror("Ошибка при удалении файла");
	}
}

Rectangle::Rectangle(const Rectangle& other) : Figure()
{
	string name = getNameFile() + " Rectangle";
	setNameFile(name);
	
	x1 = other.x1;
	x2 = other.x2;
	y1 = other.y1;
	y2 = other.y2;
	
	saveToFile();
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{	
	// Защита от самоприсваивания (например, a = a;)
	if (this == &other)
	{
		cout << "Присваивать самого на себя объекты НЕЛЬЗЯ!" << endl;
		return *this;
	}
	
	x1 = other.x1;
	x2 = other.x2;
	y1 = other.y1;
	y2 = other.y2;
	
	saveToFile();
	
	return *this;
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

string Rectangle::toString()
{
	loadFromFile();
	string line_out;
	string str_x1 = std::to_string(x1);
	string str_x2 = std::to_string(x2);
	string str_y1 = std::to_string(y1);
	string str_y2 = std::to_string(y2);
	
	line_out += "x1 = " + str_x1 + "\n";
	line_out += "x2 = " + str_x2 + "\n";
	line_out += "y1 = " + str_y1 + "\n";
	line_out += "y2 = " + str_y2 + "\n";
	
	return line_out;
}

void Rectangle::setCoordinates(int other_x1, int other_x2, int other_y1, int other_y2)
{
	x1 = other_x1;
	x2 = other_x2;
	y1 = other_y1;
	y2 = other_y2;
	
	saveToFile();
}
