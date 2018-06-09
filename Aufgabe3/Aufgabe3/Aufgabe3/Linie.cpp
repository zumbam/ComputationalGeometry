#include "stdafx.h"
#include "Linie.h"



Line::Line()
{
	p = { 0,0 };
	q = { 0,0 };
}

Line::Line(Point _p, Point _q)
{
	p = _p;
	q = _q;
}

void Line::slope()
{
	//TODO
}

void Line::intercept()
{
	//TODO
}

void Line::swapPQ()
{
	Point t = q;
	q = p;
	p = t;
}

