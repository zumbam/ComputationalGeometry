#pragma once
#include "LineSegment.h"
#include <vector>
#include <iostream>
#include "Schnitte.h"
class SweepLine
{
public:
	//datenstrktur der Sweepline
	std::vector<LineSegment> sweepLine;
	

	SweepLine();
	~SweepLine();
	//fügt an stelle von y ein
	void insert(LineSegment _lineSegment);
	//entfernt an stelle von y
	void remove(LineSegment _lineSegment);
	//tauscht zwei elemente
	void swap(int i1, int i2);
	//gibt ein segment an stelle der id
	LineSegment getSegment(int _id);
	//gets the Segment before this one
	LineSegment getAbove(LineSegment _lineSegment);
	//gets the Segment after this one
	LineSegment getBelow(LineSegment _lineSegment);
	//get the index in the Sweepline using the id of the _lineSegment
	int getSegmentPosition(LineSegment _lineSegment);
	//gets the index from id
	int getSegmentPosition(int _id);
};

