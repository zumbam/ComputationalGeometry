#pragma once

#include "Polygon.h"
#include <iostream>


float static calcAreaOfPolygon(const Polygon &polygon) {
	float area = 0.f;
	// point n + 1 is the same as in 0
	size_t n = polygon.PointList.size() - 1;

	for (int i = 1; i <= n; i++) {
		area += polygon.PointList[i % n].y  * (polygon.PointList[(i - 1)%n].x - polygon.PointList[(i + 1) % n].x);
	}
	return area/2;


}

void static calcMaxMin(const Polygon &polygon, float& minX, float& maxX, float& minY, float& maxY) {

	minX = 0.f;
	maxX = 0.f;
	minY = 0.f;
	maxY = 0.f;

	for (auto iter = polygon.PointList.begin(); iter != polygon.PointList.end(); iter++) {
		minX = (iter->x < minX) ? iter->x : minX;
		maxX = (iter->x > maxX) ? iter->x : maxX;	
		minY = (iter->y < minY) ? iter->y : minY;
		maxY = (iter->y > maxY) ? iter->y : maxY;
	}
}

float static pointInPolygon(const Polygon &polygon, const Point2D& Point) {
	float minX = 0.f;
	float maxX = 0.f;
	float minY = 0.f;
	float maxY = 0.f;

	calcMaxMin(polygon, minX, maxX, minY, maxY);

	Point2D P_snake(minX - 1, minY - 1);


	

}