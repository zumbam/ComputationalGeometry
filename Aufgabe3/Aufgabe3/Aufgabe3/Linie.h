#pragma once
#include "Point.h"

class Line
{
public:
	Point p, q;
	float m,t;
	Line();
	Line(Point _p,Point _q);
	//rechnet x aus f�r mx+t
	void slope();
	//rechnet t aus f�r mx+t
	void intercept();
	void swapPQ();
};

