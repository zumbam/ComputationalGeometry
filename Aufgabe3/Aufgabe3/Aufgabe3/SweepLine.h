#pragma once
#include "LineSegment.h"
#include <vector>
class SweepLine
{
	std::vector<LineSegment> linienSegmente;
	
public:
	SweepLine();
	~SweepLine();
	void insert(LineSegment _lineSegment);
	void remove(LineSegment);
	void swap(LineSegment);
};

