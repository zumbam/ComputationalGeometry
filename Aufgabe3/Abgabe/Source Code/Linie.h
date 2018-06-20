#pragma once
#include "Point.h"

class Line
{
public:
	Point p, q;
	//steigung(slope) und achsenabschnitt(intercept)
	float m,t;
	//uninitialized Line all values -1
	Line();
	//Line from two points
	Line(Point _p,Point _q);
	//rechnet x aus für mx+t
	void slope();
	//rechnet t aus für mx+t
	void intercept();
	//punkte tauschen
	void swapPQ();
	//berehnet y an der stelle x
	float getYat(float x);
};

