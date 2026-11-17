#include <iostream>
#include <string>
#include <fstream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle() : Figure()
{
	string name = getNameFile() + " Rectangle";
	setNameFile(name);
}

Rectangle::~Rectangle()
{
	
}


