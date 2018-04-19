#include "stdafx.h"
#include "Strecke.h"



Strecke::~Strecke()
{
}

Strecke::Strecke(float _p1, float _p2, float _q1, float _q2)
{
	p1 = _p1;
	p2 = _p2;
	q1 = _q1;
	q2 = _q2;
}

float Strecke::CCW(float r1, float r2)
{
	return (p1*q1 - p2 * q1) + (q1*r1 - q2 * r1) + (p2*r1 - p1 * r1);
 
}
