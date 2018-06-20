#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include <iostream>
#include <string>




class Point2D{

public:
	float x;
	float y;


	Point2D() {
	}

	Point2D(float x, float y) {
		this->x = x;
		this->y = y;
	}



	friend std::ostream& operator<<(std::ostream& stream,const Point2D& point) {
		return stream << point.x << "\t" << point.y << std::endl;
	} 

	friend Point2D operator+(const Point2D& self, const Point2D& other) {
		return Point2D(self.x + other.x, self.y + other.y);
	}


};

class Polygon {


public:

	std::vector<Point2D> PointList;

	Polygon() {

	}

	void addPoint(Point2D& point) {
		PointList.push_back(point);
	}


	friend std::ostream& operator<<(std::ostream& stream, const Polygon& polygon) {

		for (auto iter = polygon.PointList.begin(); iter != polygon.PointList.end(); iter++) {
			stream << (*iter);
		}
		return stream;
	}
};

class BundesLand {

public:
std::vector<Polygon> patches;
std::string name;

BundesLand() {
}

BundesLand(std::vector<Polygon> & patches, std::string & name) {
	this->patches = patches;
	this->name = name;
}

friend std::ostream& operator<<(std::ostream& stream, const BundesLand& bundesland) {

	stream << "Bundesland id:\t" << bundesland.name << std::endl;

	for (auto iter = bundesland.patches.begin(); iter != bundesland.patches.end(); iter++) {
		stream << (*iter) << std::endl;
	}
	return stream;
}
};

class Stadt {
public:

	Stadt(const std::string &name, const Point2D &center) {
		this->name = name;
		this->center = center;
	}
	Point2D center;
	std::string name;

};

#endif