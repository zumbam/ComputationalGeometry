// LinienKreuzen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "Point.h"

using namespace std;

float ccw(Point p, Point q, Point r) {
	float a=0, b=0, c = 0;
	a = (p.x*q.y - p.y*q.x);
	b = (q.x*r.y - q.y*r.x);
	c=(p.y*r.x - p.x*r.y);
	return a + b + c;
}

bool schnitt(Point p1, Point p2, Point q1, Point q2) {
	float test1 = ccw(p1, p2, q1)*ccw(p1, p2, q2);
	float test2 = ccw(q1, q2, p1)*ccw(q1, q2, p2);
	cout << "die Strecken: " << p1.print() << ", " << p2.print()<<" und " << q1.print() << ", " << q2.print() << endl;
	if (test1<=0&&test2<=0)
	{
		cout << "schneiden sich" << endl;
		return true;
	}
	else
	{
		cout << "schneiden sich nicht" << endl;
		return false;
	}
}


int main()
{

	//Geraden Überlagern sich
	Point p1,p2,q1,q2;
	p1 = { 0,0 };
	p2 = { 1,1};
	q1 = { 0,0 };
	q2 = { 2,2 };

	schnitt(p1, p2, q1, q2);

	//Geraden schneiden sich sauber
	Point a1, a2, b1, b2;
	a1 = { 0,0 };
	a2 = { 1,1 };
	b1 = { 0,1 };
	b2 = { 1,0 };

	schnitt(a1, a2, b1, b2);

	//Geraden parallel

	Point e1, e2, f1, f2;

	e1 = { 1,0 };
	e2 = { 2,1 };
	f1 = { 0,1 };
	f2 = { 1,2 };
	schnitt(e1, e2, b1, b2);

	int i;
	cin >> i;
    return 0;
}

