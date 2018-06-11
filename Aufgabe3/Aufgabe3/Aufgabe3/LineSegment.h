#pragma once
#include "Linie.h"

class LineSegment
{
public:
	/*id ist gleichzeitig der index der linie
	aus dem eingelesenen Lines std::vector*/
	int id;
	Line line;
	LineSegment();
	LineSegment(Line _l, int _id);
	~LineSegment();
};

