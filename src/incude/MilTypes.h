#ifndef GEOVIS_MILUTIL_MILTYPES_H
#define GEOVIS_MILUTIL_MILTYPES_H
#include <string>

//pre declare class about mil
namespace GeoVIS{
	namespace MilMath
	{
		class MilGeometry;
	}
	namespace MilUtil
	{
		class SymbolLib;
	}
}


struct MilSymbolInfo
{
    int code;
    int libId;
    std::string name;
};

struct GVCoord
{
	double lon;
	double lat;
	double alt;

	GVCoord();
	GVCoord(double lon, double lat, double alt);
	// GVCoord(const osg::Vec2 &lonLat, double alt);
	bool equal(const GVCoord &c) const;
	bool valid() const;
	// osg::Vec2 toVec2() const;
	GVCoord operator+(const GVCoord &coord) const;
	GVCoord operator-(const GVCoord &coord) const;
	// GVCoord operator+(const osg::Vec2 &vec) const;
	GVCoord operator*(double s) const;
	static GVCoord average(const GVCoord &c1, const GVCoord &c2);
	void normalize();
	double length();
};

struct GVDirection
{
	double heading;
	double pitch;
	double roll;

	GVDirection();
	GVDirection(double heading, double pitch, double roll);
	bool equal(const GVDirection &dir) const;
};

struct Word   //�������ݽṹ
{
	std::string content;
	float wordColor[4];//ARGB
	int width;
	int height;
	int position[2];
	std::string font;     //����
};

#endif // GEOVIS_MILUTIL_MILTYPES_H
