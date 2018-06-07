#include "stdafx.h"
#include "Point.h"


Point::Point()
{
	x = 0.0f;
	y = 0.0f;
}

Point::Point(float _x, float _y) {
	x = _x;
	y = _y;
}

string Point::float2string(float i)
{
	stringstream out;
	out << i;
	return out.str();
}

string Point::print()
{
	return float2string(x) + " " + float2string(y);
}


Point Point::operator+(Point other)
{
	return Point(x + other.x, y + other.y);
}

Point Point::operator-(Point other)
{
	return Point(x - other.x, y - other.y);
}

Point Point::operator*(float factor)
{
	return Point(x*factor, y*factor);
}

Point Point::operator/(float factor)
{
	return Point(x / factor, y / factor);
}

Point::~Point()
{
}
