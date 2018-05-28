#pragma once

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include"Linie.h"
#include <vector>
#include <fstream>
#include <chrono>


using namespace std;

//vector <Linie> linien;
//int schnitte = 0, kolinear = 0, rest = 0, kolinar_mit_überlappung = 0;

void RawAlgorithm(string filepath);

bool istLinie(Linie linie);

void readLines(string filepath);

float ccw(Point p, Point q, Point r);

bool ueberlappungstest(Point p1, Point p2, Point q1, Point q2);

void schnitt(Point p1, Point p2, Point q1, Point q2);

void schnitt(Linie l1, Linie l2);

void Testcases();

void Testcases2();
