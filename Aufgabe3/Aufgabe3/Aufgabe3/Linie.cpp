#include "stdafx.h"
#include "Linie.h"


Line::Line()
{
	p = { -1,-1 };
	q = { -1,-1 };
}

Line::Line(Point _p, Point _q)
{
	p = _p;
	q = _q;
}

void Line::slope()
{
	m = (q.y - p.y) / (q.x - p.x);

}

void Line::intercept()
{
	t = p.y - m * p.x;
}

void Line::swapPQ()
{
	Point t = q;
	q = p;
	p = t;
}

float Line::getYat(float x)
{
	return m * x + t;
}