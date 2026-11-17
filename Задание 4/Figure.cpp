#include <iostream>
#include <string>
#include <fstream>
#include "Figure.h"
using namespace std;

int Figure::numObject = 0;

Figure::Figure()
{
	numObject++;
	string numObjToStr = to_string(numObject);
	nameFile = numObjToStr;
	cout << " '" << numObject << nameFile << "' ";
}

Figure::~Figure()
{
	
}

string Figure::getNameFile()
{
	return nameFile;
}

void Figure::setNameFile(string nameF)
{
	nameFile = nameF;
}
