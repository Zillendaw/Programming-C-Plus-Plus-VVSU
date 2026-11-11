#include "decart.h"
#include "sphera.h"
#include <cmath>
#include <iostream>

using namespace std;

Decart::Decart()
{
	x = 0; y = 0; z = 0;
}

Decart::Decart(double _x, double _y, double _z)
{
	x = _x; y = _y; z = _z;
}

Decart::operator Sphera()
{
	Sphera result;
	result.R = sqrt(x*x + y*y + z*z);
	result.lon = atan2(y,x);
	result.lat = asin(z / result.R);
	return result;
}

Decart::Decart(const Sphera &s)
{
	x = s.R * cos(s.lat)* cos(s.lon);
	y = s.R * cos(s.lat) * sin(s.lon);
	z = s.R * sin(s.lat);
}

double Decart::euclideanDistance(const Decart &p1, const Decart &p2)
{
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	double dz = p1.z - p2.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

std::ostream& operator<<(std::ostream& os, const Decart& d)
{
	os << "X = " << d.x << endl;
	os << "Y = " << d.y << endl;
	os << "Z = " << d.z << endl;
	
	return os;
}
