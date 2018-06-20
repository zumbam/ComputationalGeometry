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

bool überlappungstest(Point p1, Point p2, Point q1, Point q2) {
	float lambda_1 = (q1.x - p1.x) / (p2.x - p1.x);
	float res_1 = p1.y + lambda_1 * (p2.y - p1.y);



	float lambda_2 = (q2.x - p1.x) / (p2.x - p1.x);
	float res_2 = p1.y + lambda_2 * (p2.y - p1.y);
	//cout << "lambda_1\t" << lambda_1 << "\tlambda_2\t" << lambda_2 << endl;
	//cout << "p1_x:\t" << p1.x << "\tp1_y:\t" << p1.y << endl;
	//cout << "p2_x:\t" << p2.x << "\tp2_y:\t" << p2.y << endl;
	//cout << "q1_x:\t" << q1.x << "\tq1_y:\t" << q1.y << endl;
	//cout << "q2_x:\t" << q2.x << "\tq2_y:\t" << q2.y << endl;
	//cout << "res:\t" << (res_1) << "\tres:\t" << (res_2) << endl;

	//return (res_1 == q1.y) && (res_2 == q2.y);
	bool check_q1_in_p1_p2 = lambda_1 >= 0 && lambda_1 <= 1;
	bool check_q2_in_p1_p2 = lambda_2 >= 0 && lambda_2 <= 1;

	return check_q1_in_p1_p2 || check_q2_in_p1_p2;
}

bool schnitt(Point p1, Point p2, Point q1, Point q2) {

	float checkKolinear_1 = ccw(p1, p2, q1);
	float checkKolinear_2 = ccw(p1, p2, q2);

	float test1 = checkKolinear_1 * checkKolinear_2;
	float test2 = ccw(q1, q2, p1)*ccw(q1, q2, p2);

	if (checkKolinear_1 == 0 && checkKolinear_2 == 0)
	{
#ifdef INFO

		cout << "kolinear" << endl;
#endif // INFO

		return false;
		

	}
	else if (test1 <= 0 && test2 <= 0) {
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

Point schnittPunkt(Point A1, Point A2, Point B1, Point B2) {


	float u1 = (B2.x - B1.x)*(A1.y - B1.y) - (B2.y - B1.y)*(A1.x - B1.x);
	float u2 = (B2.y - B1.y)*(A2.x - A1.x) - (B2.x - B1.x)*(A2.y - A1.y);
	if (abs(u2) > 1e-8)
	{
		float u = u1 / u2;
		return A1 + (A2 - A1)*u;
	}
	else
	{
		
		cout << "Lines Colinear or very close"  <<endl;
		return Point(-1, -1);
	}
}

