// LinienKreuzen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include"Linie.h"
#include <vector>
#include <fstream>
#include <chrono>
#include "Event.h"

using namespace std;

vector <Linie> linien;
int schnitte = 0, kolinear = 0, rest = 0;

bool istLinie(Linie linie) {
	return !(linie.p == linie.q);
}

void readLines(string filepath) {
	Linie l;

	ifstream file;
	file.open(filepath);
	int index = 1;
	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> l.p.x >> l.p.y >> l.q.x >> l.q.y;
			if (!file.eof())
			{
				if (istLinie(l)) {
					linien.push_back(l);
				}
				else {
					cout << "Linie\t" << index << "\t hat selben Start wie End Punkt" << endl;
				}
				index++;
			}
		}
		
	}
	file.close();
}

float ccw(Point p, Point q, Point r) {
	float a = 0, b = 0, c = 0;
	a = (p.x*q.y - p.y*q.x);
	b = (q.x*r.y - q.y*r.x);
	c = (p.y*r.x - p.x*r.y);
	return a + b + c;
}

//void überlappungstest(Point p1, Point p2, Point q1, Point q) {
//	float lambda_1 = (q1.x - p1.x) / (p2.x - p1.x);
//	cout << "lambda_1\t" << lambda_1 << endl;
//
//}

void schnitt(Point p1, Point p2, Point q1, Point q2) {

	float checkKolinear_1 = ccw(p1, p2, q1);
	float checkKolinear_2 = ccw(p1, p2, q2);

	//if (checkKolinear_1 == 0 && checkKolinear_2 == 0)
	//{
	//	
	//	kolinear++;
	//}
	//else {

	float test1 = checkKolinear_1 * checkKolinear_2;
	float test2 = ccw(q1, q2, p1)*ccw(q1, q2, p2);

	if (checkKolinear_1 == 0 && checkKolinear_2 == 0) {
		kolinear++;
	}
	else if (test1 <= 0 && test2 <= 0)
	{
		schnitte++;
	}
	else
	{
		rest++;
	}
	//}
}

void schnitt(Linie l1, Linie l2) {
	schnitt(l1.p, l1.q, l2.p, l2.q);
}

//Testcases zum Prüfen ob der Schnitt korrekt war
void Testcases() {
	//Geraden Überlagern sich
	Linie p = Linie({ 0,0 }, { 1,1 });
	Linie q = Linie({ 0,0 }, { 2,2 });


	schnitt(p, q);
	cout << "Überlagerunstest: Kolinear Wert:\t" << kolinear << "\t soll wert 1"<<endl;

	//Geraden schneiden sich sauber
	Point a1, a2, b1, b2;

	a1 = { 0,0 };
	a2 = { 1,1 };
	b1 = { 0,1 };
	b2 = { 1,0 };

	schnitt(a1, a2, b1, b2);
	cout << "Schnitttest: Schnitte Wert:\t" << schnitte << "\t soll wert 1" << endl;

	//Geraden parallel

	Point e1, e2, f1, f2;

	e1 = { 1,0 };
	e2 = { 2,1 };
	f1 = { 0,1 };
	f2 = { 1,2 };
	schnitt(e1, e2, f1, f2);
	cout << "Paralleltest: Kein Schnitt und nicht kolinear:\t" << rest << "\t soll wert 1" << endl;
	
	Point g1, g2, h1, h2;
	//Teilen dengleichen Punkt
	g1 = { 0, 0 };
	g2 = { 0, 1 };
	h1 = { 0, 0 };
	h2 = { 1, 0 };
	schnitt(g1, g2, h1, h2);
	cout << "Teilen einen Punkttest: Schnitte:\t" << schnitte -1 << "\t soll wert 1" << endl; // schnitt minus wegen vorherigem test
	cout << "Teilen einen Punkttest: Kolinear:\t" << kolinear << "\t soll wert 1" << endl;
}

//alle gegen alle Testen
void RawAlgorithm(string filepath) {
	readLines(filepath);
	cout << "read "<< linien.size()<<" lines"<< endl;

	auto start_time = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < linien.size(); i++)
	{
		for (int j = i+1; j < linien.size(); j++)
		{
			schnitt(linien[i], linien[j]);
		}
		if (i % 100 == 0 && i != 0)
		{
			cout << "|";
		}
		
	}
	cout << endl;
	cout << "Schnitt: " << schnitte << " Kolinear: " << kolinear << " Rest: " << rest << endl;
	auto end_time = std::chrono::high_resolution_clock::now();
	auto time = end_time - start_time;
	std::cout << "dauer " <<
	std::chrono::duration_cast<std::chrono::milliseconds>(time).count() << "ms" << endl;

	//cleanup
	linien.clear();
	schnitte = 0;
	kolinear = 0;
	rest = 0;
}

void LineSweep() {
	vector <Event> eventQueue;
	//fill event Queue
	for (int i = 0; i < linien.size(); i++)
	{
		Event e1 = Event(-1, -1, linien[i].p.x, linien[i].p.y);
		Event e2 = Event(-1, -1, linien[i].q.x, linien[i].q.x);
		//prüfe was davon der Anfangs und Endpunkt ist
		if (e1.x < e2.x) {
			e1.idxStart = i;
			e2.idxEnd = i;
		}
		else
		{
			e1.idxEnd = i;
			e2.idxStart = i;
		}
	}
}

int main()
{
	RawAlgorithm("data/s_10_1.dat");
	//Testcases();

	int i;
	cin >> i;
	return 0;
}

