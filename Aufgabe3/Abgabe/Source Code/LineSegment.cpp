#include "stdafx.h"
#include "LineSegment.h"

//Initializes everything with -1
LineSegment::LineSegment()
{
	line = Line({ -1,-1 }, { -1, -1 });
	id = -1;
}

LineSegment::LineSegment(Line _l,int _id)
{
	line = _l;
	id = _id;
}


LineSegment::~LineSegment()
{
}
