#include "stdafx.h"

#include "Schnitte.h"

float ccw(Point p, Point q, Point r)
{
	float a = 0, b = 0, c = 0;
	a = (p.x*q.y - p.y*q.x);
	b = (q.x*r.y - q.y*r.x);
	c = (p.y*r.x - p.x*r.y);
	return a + b + c;
}

bool schnitt(Point p1, Point p2, Point q1, Point q2) {

	float checkKolinear_1 = ccw(p1, p2, q1);
	float checkKolinear_2 = ccw(p1, p2, q2);

	float test1 = checkKolinear_1 * checkKolinear_2;
	float test2 = ccw(q1, q2, p1)*ccw(q1, q2, p2);

	if (test1 <= 0 && test2 <= 0) {
		return true;
	}
	else
	{
		return false;
	}
}

bool schnitt(Line l1, Line l2) {
	return schnitt(l1.p, l1.q, l2.p, l2.q);
}

Point schnittPunkt(Line l1, Line l2) {
	return schnittPunkt(l1.p, l1.q, l2.p, l2.q);
}

Point schnittPunkt(Point p1, Point p2, Point q1, Point q2) {

	float lambda_1 = (q1.x - p1.x) / (p2.x - p1.x);
	float u1 = p1.y + lambda_1 * (p2.y - p1.y);



	float lambda_2 = (q2.x - p1.x) / (p2.x - p1.x);
	float u2 = p1.y + lambda_2 * (p2.y - p1.y);
	if (abs(u2) > 1e-8)
	{
		float u = u1 / u2;
		return p1 + (p2 - p1)*u;
	}
	else
	{
		return Point(-1, -1);
	}
}

