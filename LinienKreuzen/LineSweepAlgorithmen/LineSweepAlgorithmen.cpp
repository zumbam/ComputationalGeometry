// LineSweepAlgorithmen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "Linie.h"
#include <vector>
#include <fstream>
#include <chrono>
#include "Event.h"
#include <algorithm>

vector <Linie> linien;

vector <Event> eventQueue;
vector <Linie> sweepLine;
vector <Event> outputIntersections;

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
			
		}
		else if (e.idxEnd == -1)
		{
			//startevent
		
		}
		else
		{
			//endEvent
			
		}
	}



	int i;
	std::cin >> i;
	return 0;
}

