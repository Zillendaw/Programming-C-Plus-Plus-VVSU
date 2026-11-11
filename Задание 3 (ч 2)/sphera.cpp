#include "decart.h"
#include "sphera.h"
#include <cmath>
#include <algorithm>

using namespace std;

Sphera::Sphera()
{
	lon = 0; lat = 0; R = 0;
}

Sphera::Sphera(double _lon, double _lat, double _R)
{
	lon = _lon; lat = _lat; R = _R;
}

Sphera::operator Decart()
{
	Decart result;
	result.x = R * cos(lat)* cos(lon);
	result.y = R * cos(lat) * sin(lon);
	result.z = R * sin(lat);
	return result;
}

Sphera::Sphera(const Decart &d)
{
	R = sqrt(d.x * d.x + d.y * d.y + d.z * d.z);
	if (R == 0.0)
	{
		lon = 0.0;
		lat = 0.0;
	}
	else
	{
		lon = atan2(d.y, d.x);
		lat = asin(d.z / R);
	}
}

double Sphera::bigCircleDistance(const Sphera &p1, const Sphera &p2)
{
	const double EARTH_RADIUS = 6371000.0;

	double cosAngle = sin(p1.lat) * sin(p2.lat) +
	                  cos(p1.lat) * cos(p2.lat) * cos(p1.lon - p2.lon);

	// Защита от выхода за пределы [-1, 1] из-за погрешности вычислений с плавающей точкой
	if (cosAngle > 1.0) cosAngle = 1.0;
	if (cosAngle < -1.0) cosAngle = -1.0;

	return EARTH_RADIUS * acos(cosAngle);
}

std::ostream& operator<<(std::ostream& os, const Sphera& s)
{
	os << "lon = " << s.lon << endl;
	os << "lat = " << s.lat << endl;
	os << "R = " << s.R << endl;
	
	return os;
}
