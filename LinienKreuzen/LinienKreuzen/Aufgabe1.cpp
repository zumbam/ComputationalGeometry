#include "stdafx.h"
#include "Aufgabe1.h"

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

bool ueberlappungstest(Point p1, Point p2, Point q1, Point q2) {
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

void schnitt(Point p1, Point p2, Point q1, Point q2) {

	float checkKolinear_1 = ccw(p1, p2, q1);
	float checkKolinear_2 = ccw(p1, p2, q2);

	float test1 = ccw(p1, p2, q1) * ccw(p1, p2, q2);
	float test2 = ccw(q1, q2, p1)*ccw(q1, q2, p2);

	if (checkKolinear_1 == 0 && checkKolinear_2 == 0)
	{
		kolinear++;
		if (ueberlappungstest(p1, p2, q1, q2)) {
			kolinar_mit_überlappung++;

		}
		else {
			rest++;

		}

	}
	else if (test1 <= 0 && test2 <= 0) {
		schnitte++;
	}
	else
	{
		rest++;
	}

}

void schnitt(Linie l1, Linie l2) {
	schnitt(l1.p, l1.q, l2.p, l2.q);
}

//Testcases zum Prüfen ob der Schnitt korrekt war
void Testcases() {
	//Geraden Überlagern sich
	Linie p = Linie({ 0,0 }, { 1,1 });
	Linie q = Linie({ 0,0 }, { 2,2 });

	//kolinear 1 schnitt 0 rest 0
	schnitt(p, q);
	cout << "Ueberlagerunstest: Kolinear Wert:\t" << kolinear << "\t soll wert 1" << endl;

	//Geraden schneiden sich sauber
	Point a1, a2, b1, b2;

	a1 = { 0,0 };
	a2 = { 1,1 };
	b1 = { 0,1 };
	b2 = { 1,0 };

	//kolinear 1 schnitt 1 rest 0
	schnitt(a1, a2, b1, b2);
	cout << "Schnitttest: Schnitte Wert:\t" << schnitte << "\t soll wert 1" << endl;

	//Geraden parallel

	Point e1, e2, f1, f2;

	e1 = { 1,0 };
	e2 = { 2,1 };
	f1 = { 0,1 };
	f2 = { 1,2 };
	//kolinear 1 schnitt 1 rest 1
	schnitt(e1, e2, f1, f2);
	cout << "Paralleltest: Kein Schnitt und nicht kolinear   rest:\t" << rest << "\t soll wert 1" << endl;

	Point g1, g2, h1, h2;
	//Teilen dengleichen Punkt
	g1 = { 0, 0 };
	g2 = { 0, 1 };
	h1 = { 0, 0 };
	h2 = { 1, 0 };
	//kolinear 1 schnitt 2 rest 1
	schnitt(g1, g2, h1, h2);
	cout << "Teilen einen Punkttest: Schnitte:\t" << schnitte << "\t soll wert 2" << endl;
	cout << "Teilen einen Punkttest: Kolinear:\t" << kolinear << "\t soll wert 1" << endl;

	//Geraden Überlagern sich
	Linie i = Linie({ 0,0 }, { 3,3 });
	Linie j = Linie({ 1,1 }, { 2,2 });

	//kolinear 2 schnitt 2 rest 1
	schnitt(i, j);
	cout << "Ueberlagerunstest innerhalb: Kolinear Wert:\t" << kolinear << "\t soll wert 2" << endl;

}

void Testcases2() {
	//Fehler colinearität
	Linie P = Linie({ 0.f, 0.f }, { 0.1f, 0.1f });
	Linie Q = Linie({ 10.f, 10.f }, { 10.1f, 10.1f });
	//kolinear 0 schnitt 0 rest 1
	schnitt(P, Q);
	cout << "Fehler Kolinearität/ Kolinear Wert:\t" << kolinear << "\t soll wert 1" <<
		"\t Rest:\t" << rest << "\t soll Wert 1" << endl;

	bool res = ueberlappungstest(P.p, P.q, Q.p, Q.q);

	cout << "Ueberlappungstest:\t" << res << "soll 0" << endl;

	//Geraden Überlagern sich
	P = Linie({ 0,0 }, { 1,1 });
	Q = Linie({ 0,0 }, { 2,2 });

	//kolinear 1 schnitt 0 rest 0
	res = ueberlappungstest(P.p, P.q, Q.p, Q.q);
	cout << "Ueberlappungstest2:\t" << res << "soll 1" << endl;


	//Geraden Überlagern sich
	Linie i = Linie({ 0,0 }, { 3,3 });
	Linie j = Linie({ 1,1 }, { 2,2 });

	//kolinear 2 schnitt 0 rest 0
	res = ueberlappungstest(P.p, P.q, Q.p, Q.q);
	cout << "Ueberlappungstest2:\t" << res << "soll 1" << endl;


}

//alle gegen alle Testen
void RawAlgorithm(string filepath) {
	readLines(filepath);
	cout << "read " << linien.size() << " lines" << endl;

	auto start_time = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < linien.size(); i++)
	{
		for (int j = i + 1; j < linien.size(); j++)
		{
			schnitt(linien[i], linien[j]);
		}
		if (i % 1000 == 0 && i != 0)
		{
			cout << float(float(i) / linien.size()) * 100 << "%" << endl;
		}


	}
	cout << endl;
	cout << "Schnitte (ein Punkt): " << schnitte << endl
		<< "Schnitte (mehrere Punkte \"kolinar_mit_ueberlappung\") " << kolinar_mit_überlappung << endl
		<< "Kolinear(alle): " << kolinear << endl
		<< "Rest: " << rest << endl;
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