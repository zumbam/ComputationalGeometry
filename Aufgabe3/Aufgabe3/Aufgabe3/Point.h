#pragma once
#include <string>
#include <sstream>
using namespace std;
class Point
{
public:
	Point();
	Point(float _x, float _y);
	string float2string(float i);

	string print();

	Point operator+(Point other);

	Point operator-(Point other);

	Point operator*(float factor);

	Point operator/(float factor);

	bool operator==(Point point) {
		return this->x == point.x && this->y == point.y;
	}

	~Point();
	float x;
	float y;
};

