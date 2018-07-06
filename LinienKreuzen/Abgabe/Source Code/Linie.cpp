#include "stdafx.h"
#include "Linie.h"



Linie::Linie()
{
	p = { 0,0 };
	q = { 0,0 };
}

Linie::Linie(Point _p, Point _q)
{
	p = _p;
	q = _q;
}

