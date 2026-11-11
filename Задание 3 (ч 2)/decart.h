#ifndef DECART_H
#define DECART_H
#include <iostream>

class Sphera;

class Decart
{
public:
	double x,y,z;
	Decart();
	Decart(const Sphera &s);
	Decart(double _x, double _y, double _z);
	
	explicit operator Sphera();
	static double euclideanDistance(const Decart &p1, const Decart &p2);
	
};

std::ostream& operator<<(std::ostream& os, const Decart& d);

#endif // DECART_H
