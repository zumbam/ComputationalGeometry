#pragma once


#include "Polygon.h"
#include "PolygonAlgorithm.h"



void static test_1() {

	Point2D p1(0.f, 0.f);
	Point2D p2(1.f, 0.f);
	Point2D p3(0.f, 1.f);
	Polygon poly;
	
	poly.addPoint(p1);
	poly.addPoint(p2);
	poly.addPoint(p3);
	poly.addPoint(p1);

	std::cout << "polygon\n" << poly << "area" << calcAreaOfPolygon(poly) <<std::endl;

}

void static test_2() {

	Point2D p1(0.f, 0.f);
	Point2D p2(1.f, 0.f);
	Point2D p3(1.f, 1.f);
	Point2D p4(0.f, 1.f);
	Polygon poly;

	poly.addPoint(p1);
	poly.addPoint(p2);
	poly.addPoint(p3);
	poly.addPoint(p4);
	poly.addPoint(p1);

	std::cout << "polygon\n" << poly << "area" << calcAreaOfPolygon(poly) << std::endl;

}

void static test_min_max() {

	Point2D p1(-5.f, 0.f);
	Point2D p2(1.f, 10.f);
	Point2D p3(30.f, 1.f);
	Point2D p4(0.f, -20.f);
	Polygon poly;

	poly.addPoint(p1);
	poly.addPoint(p2);
	poly.addPoint(p3);
	poly.addPoint(p4);
	poly.addPoint(p1);

	float minX = 0.f;
	float maxX = 0.f;
	float minY = 0.f;
	float maxY = 0.f;

	calcMaxMin(poly, minX, maxX, minY, maxY);

	std::cout << poly << std::endl;
	std::cout << "minX:\t" << minX << std::endl;
	std::cout << "maxX:\t" << maxX <<std::endl;
	std::cout << "minY:\t" << minY << std::endl;
	std::cout << "maxY:\t" << maxY << std::endl;

}