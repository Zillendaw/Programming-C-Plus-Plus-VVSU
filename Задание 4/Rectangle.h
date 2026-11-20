#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <string>
#include <fstream>
#include "Figure.h"
using namespace std;

class Rectangle : public Figure
{
	
public:
	Rectangle();
	
	Rectangle(int x1, int x2, int y1, int y2);
	
	virtual ~Rectangle();
	
	Rectangle (const Rectangle& other);
	
	Rectangle& operator=(const Rectangle& other);
	
	void setCoordinates(int x1, int x2, int y1, int y2);
	virtual void loadFromFile() override;
	virtual void saveToFile() override;
	virtual string toString() override;
	
private:
	int x1;
	int x2;
	int y1;
	int y2;
};


#endif // RECTANGLE_H
