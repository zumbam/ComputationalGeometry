#pragma once
#include <string>
#include <sstream>
using namespace std;
class Point
{
public:
	float x;
	float y;

	//uninitialized all values -1
	Point();
	//Point from x and y
	Point(float _x, float _y);

	string float2string(float i);
	//string representation of a Point
	string print();

	Point operator+(Point other);

	Point operator-(Point other);

	Point operator*(float factor);

	Point operator/(float factor);

	bool operator==(Point point) {
		return this->x == point.x && this->y == point.y;
	}

	~Point();

};

