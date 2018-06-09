#include "stdafx.h"

#include "Schnitte.h"

float ccw(Point p, Point q, Point r)
{
	return 0.0f;
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

Point LineCollision(Line l1, Line l2) {
	return LineCollision(l1.p, l1.q, l2.p, l2.q);
}

Point LineCollision(Point A1, Point A2, Point B1, Point B2) {

	float u1 = (B2.x - B1.x)*(A1.y - B1.y) - (B2.y - B1.y)*(A1.x - B1.x);
	float u2 = (B2.y - B1.y)*(A2.x - A1.x) - (B2.x - B1.x)*(A2.y - A1.y);
	if (abs(u2) > 1e-8)
	{
		float u = u1 / u2;
		return A1 + (A2 - A1)*u;
	}
	else
	{
		return Point(-1, -1);
	}
}
