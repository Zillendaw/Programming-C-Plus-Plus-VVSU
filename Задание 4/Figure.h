#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Figure
{
	
public:
	Figure();
	
	virtual ~Figure() = 0;
	
	string getNameFile();
	
	void setNameFile(string name_f);

	
	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
	virtual string toString() = 0;
	
private:
	string nameFile;
	static int numObject;
};


#endif // FIGURE_H
