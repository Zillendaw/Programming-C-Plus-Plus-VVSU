#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <string>
#include <fstream>
#include "Figure.h"
using namespace std;

class Triangle : public Figure
{
	
public:
	Triangle();
	
	Triangle(int x1, int x2, int x3, int y1, int y2, int y3);
	
	virtual ~Triangle();
	
	Triangle (const Triangle& other);
	
	Triangle& operator=(const Triangle& other);
	
	void setCoordinates(int x1, int x2, int x3, int y1, int y2, int y3);
	virtual void loadFromFile() override;
	virtual void saveToFile() override;
	virtual string toString() override;
	
private:
	int x1;
	int x2;
	int x3;
	int y1;
	int y2;
	int y3;
};


#endif // TRIANGLE_H
