// LineSweepAlgorithmen.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "LineSweepAlgorithmen.h"

bool istLinie(Line linie) {
	return !(linie.p == linie.q);
}

bool istVertical(Line line) {
	return (line.p.x == line.q.x);
}

void readLines(string filepath) {
	Line l;

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
					if (!istVertical(l))
					{
						lines.push_back(l);
					}
					else
					{
						cout << "Linie\t" << index << "\t ist Vertikal" << endl;
					}
					

				}
				else {
					cout << "Linie\t" << index << "\t hat selben Start wie End Punkt" << endl;
				}
				index++;
			}
		}

	}
	else
	{
		std::cout << "file not found" << std::endl;
	}
	file.close();
}



int main()
{
	readLines("data/s_10_1.dat");
	for (int i = 0; i < lines.size(); i++)
	{
		if (lines[i].p.x > lines[i].q.x)
		{
			lines[i].swapPQ();
		}
	}
	eventQueue.fill(lines);
	//eventQueue.sort();

	//Sweepline Algorithmus
	while (eventQueue.size() > 0)
	{
		Event e = eventQueue.front();
		if (e.idxEnd == -1 && e.idxStart == -1)
		{
			//error/uninitalized
			std::cout << "ERROR: Event uninitialized";
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
		e.print();
		//remove first element from event queue
		eventQueue.remove(0);
	}
	int i;
	std::cin >> i;
	return 0;
}

void handleStartEvent(Event _e) {


}

void handleEndEvent(Event _e) {

}

void handleIntersectionEvent(Event _e) {

}