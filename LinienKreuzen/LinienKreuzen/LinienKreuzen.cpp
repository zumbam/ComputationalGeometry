// LinienKreuzen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "Point.h"

using namespace std;

float ccw(Point p, Point q, Point r) {
	return((p.x*q.y - p.y*q.x) + (q.x*r.y - q.y*r.x) + (p.y*r.x - p.x*r.y));
}

bool schnitt(Point p1, Point p2, Point q1, Point q2) {
	float test1 = ccw(p1, p2, q1)*ccw(p1, p2, q2);
	float test2 = ccw(q1, q2, p1)*ccw(q1, q2, p2);
	if (test1<=0&&test2<=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{





	int i;
	cin >> i;
    return 0;
}

