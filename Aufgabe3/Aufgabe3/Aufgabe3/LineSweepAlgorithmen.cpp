// LineSweepAlgorithmen.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "LineSweepAlgorithmen.h"

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

//sortierungs vorgabe
bool sortingCondition(Event i, Event j)
{
	//lowest element at end
	return i.x > j.x;
}

float ccw(Point p, Point q, Point r)
{
	return 0.0f;
}

bool überlappungstest(Point p1, Point p2, Point q1, Point q2)
{
	return false;
}

bool schnitt(Point p1, Point p2, Point q1, Point q2)
{
	return false;
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


bool schnitt(Linie l1, Linie l2) {
	return schnitt(l1.p, l1.q, l2.p, l2.q);
}


int main()
{
	readLines("data/s_10_1.dat");
	
	//fuelle event Queue
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
		eventQueue.push_back(e1);
		eventQueue.push_back(e2);
	}

	//sort event Queue by x
	std::sort(eventQueue.begin(), eventQueue.end(), sortingCondition);

	//Sweepline Algorithmus
	while (eventQueue.size()>0)
	{
		Event e = eventQueue.back();
		if (e.idxEnd == -1 && e.idxStart == -1)
		{
			//error/uninitalized
			cout << "ERROR: Event uninitialized";
		}
		else if (e.idxEnd != -1 && e.idxStart != -1)
		{
			//intersection event
			handleIntersectionEvent(e);
			
		}
		else if (e.idxEnd == -1)
		{
			//startevent
			handleStartEvent(e);
		
		}
		else
		{
			//endEvent
			handleEndEvent(e);
			
		}
	}



	int i;
	std::cin >> i;
	return 0;
}

void handleStartEvent(Event _e) {
	Linie segE = linien[_e.idxStart];
	int index = 0;
	//insert element into SL
	for (int i = 0; i < sweepLine.size(); i++)
	{
		Linie l = sweepLine[i];
		if (_e.y>l.p.y)
		{
			sweepLine.insert(sweepLine.begin() + i,segE );
			index = i;
			break;
		}
	}
	Linie segA = sweepLine[index];
	Linie segB = sweepLine[index + 2];

	//Intersect
	if (schnitt(segE,segA))
	{
		
	}

}

void handleEndEvent(Event _e) {

}

void handleIntersectionEvent(Event _e) {

}