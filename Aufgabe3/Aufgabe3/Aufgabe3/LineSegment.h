#pragma once
#include "Linie.h"
class LineSegment
{
public:
	int index;
	Line linie;

	LineSegment(Line _l, int _index);
	~LineSegment();
};

