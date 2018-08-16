#include <GVMilUtil/MilTypes.h>

#include <math.h>

GVCoord::GVCoord()
: lat(39.9)
, lon(116.3)
, alt(1000.0)
{

}

GVCoord::GVCoord(double lon, double lat, double alt)
{
	this->lon = lon;
	this->lat = lat;
	this->alt = alt;
}


bool GVCoord::equal(const GVCoord &c) const
{
	return c.lat == lat &&
		c.lon == lon &&
		c.alt == alt;
}


bool GVCoord::valid() const
{
	if (lat > 90.0 || lat < -90.0)
		return false;
	return true;
}

GVCoord GVCoord::operator+(const GVCoord &coord) const
{
	double nlon = lon + coord.lon;
	double nlat = lat + coord.lat;
	double nalt = alt + coord.alt;

	while (nlon > 180.0)
		nlon -= 360.0;
	while (nlon < -180)
		nlon += 360.0;

	return GVCoord(nlon, nlat, nalt);
}

GVCoord GVCoord::operator-(const GVCoord &coord) const
{
	double nlon = lon - coord.lon;
	double nlat = lat - coord.lat;
	double nalt = alt - coord.alt;

	while (nlon > 180.0)
		nlon -= 360.0;
	while (nlon < -180)
		nlon += 360.0;

	return GVCoord(nlon, nlat, nalt);
}

GVCoord GVCoord::operator*(double s) const
{
	return GVCoord(lon*s, lat*s, alt*s);
}

GVCoord GVCoord::average(const GVCoord &c1, const GVCoord &c2)
{
	return GVCoord((c1.lon + c2.lon)*0.5, (c1.lat + c2.lat)*0.5, (c1.alt + c2.alt)*0.5);
}

void GVCoord::normalize()
{
	double sum = 0.0;
	sum = pow(lon,2) + pow(lat,2) + pow(alt,2);
	
	if(fabs(sum - 0) < 1E-8)
		return;

	lon = lon / sqrt(sum);
	lat = lat / sqrt(sum);
	alt = alt / sqrt(sum);
}

double GVCoord::length()
{
	double sum = 0.0;
	sum = pow(lon,2) + pow(lat,2) + pow(alt,2);

	return sqrt(sum);
}

GVDirection::GVDirection()
: heading(0)
, pitch(0)
, roll(0)
{

}

GVDirection::GVDirection(double heading, double pitch, double roll)
{
	this->heading = heading;
	this->pitch = pitch;
	this->roll = roll;
}

bool GVDirection::equal(const GVDirection &dir) const
{
	return 	(fabs(dir.heading - heading) < 1e-6) &&
		(fabs(dir.pitch - pitch) < 1e-6) &&
		(fabs(dir.roll - roll) < 1e-6);
}


