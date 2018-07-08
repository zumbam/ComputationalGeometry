#pragma once

#include "Polygon.h"
#include <iostream>



float static calcAreaOfPolygon(const Polygon &polygon) {
	float area = 0.f;
	// point n + 1 is the same as in 0
	size_t n = polygon.PointList.size() - 1;

	for (int i = 1; i <= n; i++) {
		area += polygon.PointList[i % n].y  * (polygon.PointList[(i - 1) % n].x - polygon.PointList[(i + 1) % n].x);
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

float static ccw(const Point2D &p,const Point2D &q, const Point2D &r) {
	float a = 0, b = 0, c = 0;
	a = (p.x*q.y - p.y*q.x);
	b = (q.x*r.y - q.y*r.x);
	c = (p.y*r.x - p.x*r.y);
	return a + b + c;
}

static float sign(const float &v) {
	return (v == 0) ? 0 : (v < 0 ? -1 : 1);
}

bool static pointInPolygon(const Polygon &polygon, const Point2D& q) {
	float minX = 0.f;
	float maxX = 0.f;
	float minY = 0.f;
	float maxY = 0.f;

	calcMaxMin(polygon, minX, maxX, minY, maxY);

	// making sure its not lying in the polygon
	Point2D p_snake(minX - 1, minY - 1);


	// find real side change
	int lr=0;
	int i = 0;
	for(Point2D p : polygon.PointList) {
		// getting last sign
		lr = sign(ccw(p_snake, q, p));
		if ( lr != 0) {
			// break wenn good start point is found
			break;
		}
		i++;
	}
	int cut_count = 0;
	int lr_new = 0;
	for (int j = i +1 ; j < polygon.PointList.size(); j++) {
		int num_points = polygon.PointList.size();
		// edges witch are not start point has to been check later as well (cube test)
		//int z = (j + 1 + i) % num_points;
		Point2D p = polygon.PointList[j];
		lr_new = sign(ccw(p_snake, q, p));
		// check if its a real side change
		if (abs(lr_new - lr) == 2) {
			lr = lr_new;
			//int z_ = (z - 1) % num_points;
			Point2D p_last = polygon.PointList[j-1];
			// check if for real cut
			if (ccw(p_last, p, q) * ccw(p_last, p, p_snake) <= 0) {
				cut_count++;
			}

		
		}
	
	
	}
	return (cut_count % 2);
}