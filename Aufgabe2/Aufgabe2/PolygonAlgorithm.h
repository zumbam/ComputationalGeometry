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