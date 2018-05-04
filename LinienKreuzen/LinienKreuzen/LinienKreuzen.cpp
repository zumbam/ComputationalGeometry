// LinienKreuzen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include"Linie.h"
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

vector <Linie> linien;
int schnitte = 0,kolinear=0,rest=0;

float ccw(Point p, Point q, Point r) {
	float a=0, b=0, c = 0;
	a = (p.x*q.y - p.y*q.x);
	b = (q.x*r.y - q.y*r.x);
	c=(p.y*r.x - p.x*r.y);
	return a + b + c;
}

void schnitt(Point p1, Point p2, Point q1, Point q2) {
	float test1 = ccw(p1, p2, q1)*ccw(p1, p2, q2);
	float test2 = ccw(q1, q2, p1)*ccw(q1, q2, p2);
	if (test1<=0&&!test2<=0)
	{
		schnitte++;
	}
	else if (test1==0&&test2==0)
	{
		kolinear++;
	}
	else
	{
		rest++;
	}
}

void readLines(string filepath,int anzahl) {
	Linie l;

	ifstream file;
	file.open(filepath);
	if (file.is_open())
	{
		for (int i = 0; i < anzahl; i++)
		{
			file >> l.p.x >> l.p.y >> l.q.x >> l.q.y;
			linien.push_back(l);
		}
	}
	file.close();
}

void schnitt(Linie l1, Linie l2) {
	schnitt(l1.p, l1.q, l2.p, l2.q);
}

void Testcases() {
	//Geraden Überlagern sich
	Linie p = Linie({ 0,0 }, { 1,1 });
	Linie q = Linie({ 0,0 }, { 2,2 });


	schnitt(p,q);

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
	schnitt(e1, e2, f1, f2);
}

int main()
{
	readLines("Data/s_100000_1.dat", 100000);
	cout << "reading successful" << endl;

	auto start_time = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < linien.size(); i++)
	{
		for (int j = i; j < linien.size(); j++)
		{
			schnitt(linien[i], linien[j]);
		}
		if (i%100==0&&i!=0)
		{
			cout << "|";
		}
	}
	cout << "Schnitt: " << schnitte << " Kolinear: " << kolinear << " Rest: " << rest << endl;
	auto end_time = std::chrono::high_resolution_clock::now();
	auto time = end_time - start_time;
	std::cout << "dauer " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(time).count() << "ms"<<endl;
	int i;
	cin >> i;
    return 0;
}

