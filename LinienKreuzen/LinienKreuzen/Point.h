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

	bool operator==(Point point){
		return this->x == point.x && this->y == point.y;
	}

	~Point();
	float x;
	float y;
};

