#pragma once
#include "Linie.h"

float ccw(Point p, Point q, Point r);

bool schnitt(Point p1, Point p2, Point q1, Point q2);

bool schnitt(Line l1, Line l2);

Point LineCollision(Line l1, Line l2);

Point LineCollision(Point A1, Point A2, Point B1, Point B2);
