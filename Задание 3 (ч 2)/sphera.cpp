#include "decart.h"
#include "sphera.h"
#include <math.h>

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
