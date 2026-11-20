#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include "Triangle.h"
using namespace std;

Triangle::Triangle() : Figure()
{
	x1 = 0;
	x2 = 0;
	x3 = 0;
	y1 = 0;
	y2 = 0;
	y3 = 0;
	string name = getNameFile() + " Triangle";
	setNameFile(name);
	saveToFile();
}

Triangle::Triangle(int input_x1, int input_x2, int input_x3, int input_y1, int input_y2, int input_y3) : Figure()
{
	x1 = input_x1;
	x2 = input_x2;
	x3 = input_x3;
	y1 = input_y1;
	y2 = input_y2;
	y3 = input_y3;
	string name = getNameFile() + " Triangle";
	setNameFile(name);
	saveToFile();
}

Triangle::~Triangle()
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

Triangle::Triangle(const Triangle& other) : Figure()
{
	string name = getNameFile() + " Triangle";
	setNameFile(name);
	
	x1 = other.x1;
	x2 = other.x2;
	x3 = other.x3;
	y1 = other.y1;
	y2 = other.y2;
	y3 = other.y3;
	
	saveToFile();
}

Triangle& Triangle::operator=(const Triangle& other)
{	
	// Защита от самоприсваивания (например, a = a;)
	if (this == &other)
	{
		cout << "Присваивать самого на себя объекты НЕЛЬЗЯ!" << endl;
		return *this;
	}
	
	x1 = other.x1;
	x2 = other.x2;
	x3 = other.x3;
	y1 = other.y1;
	y2 = other.y2;
	y3 = other.y3;
	
	saveToFile();
	
	return *this;
}

void Triangle::saveToFile()
{
	ofstream file (getNameFile());
	
	if (!file.is_open())
	{
		cout << "ОШИБКА С ФАЙЛОМ ВОВРЕМЯ ЗАПИСИ! Программа закрывается...";
		exit(EXIT_FAILURE);
	}
	
	file << x1 << " ";
	file << x2 << " ";
	file << x3 << " ";
	file << y1 << " ";
	file << y2 << " ";	
	file << y3 << " ";
	
	file.close();
}

void Triangle::loadFromFile()
{
	ifstream file (getNameFile());
	
	if (!file.is_open())
	{
		cout << "ФАЙЛ НЕ ОТКРЫЛСЯ! Программа закрывается...";
		exit(EXIT_FAILURE);
	}
	
	file >> x1;
	file >> x2;
	file >> x3;
	file >> y1;
	file >> y2;
	file >> y3;	
	
	file.close();
}

string Triangle::toString()
{
	loadFromFile();
	string line_out;
	string str_x1 = std::to_string(x1);
	string str_x2 = std::to_string(x2);
	string str_x3 = std::to_string(x3);
	string str_y1 = std::to_string(y1);
	string str_y2 = std::to_string(y2);
	string str_y3 = std::to_string(y3);
	
	line_out += "x1 = " + str_x1 + "\n";
	line_out += "x2 = " + str_x2 + "\n";
	line_out += "x3 = " + str_x3 + "\n";
	line_out += "y1 = " + str_y1 + "\n";
	line_out += "y2 = " + str_y2 + "\n";
	line_out += "y3 = " + str_y3 + "\n";
	
	return line_out;
}

void Triangle::setCoordinates(int other_x1, int other_x2, int other_x3, int other_y1, int other_y2, int other_y3)
{
	x1 = other_x1;
	x2 = other_x2;
	x3 = other_x3;
	y1 = other_y1;
	y2 = other_y2;
	y3 = other_y3;
	
	saveToFile();
}
