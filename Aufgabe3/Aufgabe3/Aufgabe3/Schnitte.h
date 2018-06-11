#pragma once
#include "Linie.h"

float ccw(Point p, Point q, Point r);

//prüft einen schnitt mit ccw
bool schnitt(Point p1, Point p2, Point q1, Point q2);
//prüft einen schnitt mit ccw
bool schnitt(Line l1, Line l2);
//gibt den genauen schnittort aus
Point schnittPunkt(Line l1, Line l2);
//gibt den genauen Schnittort aus
Point schnittPunkt(Point A1, Point A2, Point B1, Point B2);

