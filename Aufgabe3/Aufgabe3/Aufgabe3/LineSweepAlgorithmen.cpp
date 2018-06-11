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
		lines[i].slope();
		lines[i].intercept();
	}

	eventQueue.fill(lines);
	eventQueue.sort();

	//Sweepline Algorithmus
	while (!eventQueue.empty())
	{
		Event e = eventQueue.front();
		e.print();
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

		//remove first element from event queue
		eventQueue.remove(0);
	}

	cout << "Output intersections: " << outputIntersections.size() << endl;
	int i;
	std::cin >> i;
	return 0;
}

void handleStartEvent(Event _e) {
	LineSegment segE = LineSegment(lines[_e.idxStart], _e.idxStart);
	sweepLine.insert(segE);
	LineSegment segA = sweepLine.getAbove(segE);
	//if SegA exists
	if (segA.id != -1)
	{
		//schnitt existiert
		if (schnitt(segE.line, segA.line))
		{
			Point EA = schnittPunkt(segE.line, segA.line);
			Event intersectEA = Event(segE.id, segA.id, EA.x, EA.y);
			eventQueue.insert(intersectEA);
		}
	}
	LineSegment segB = sweepLine.getBelow(segE);
	//if SegB exists
	if (segB.id != -1)
	{
		//schnitt existiert
		if (schnitt(segE.line, segB.line))
		{
			Point EB = schnittPunkt(segE.line, segA.line);
			Event intersectEB = Event(segE.id, segB.id, EB.x, EB.y);
			eventQueue.insert(intersectEB);
		}
	}
}

void handleEndEvent(Event _e) {
	LineSegment segE = LineSegment(lines[_e.idxEnd], _e.idxEnd);
	LineSegment segA = sweepLine.getAbove(segE);
	LineSegment segB = sweepLine.getBelow(segE);
	sweepLine.remove(segE);
	//schnitt existiert
	if (segA.id!=-1&&segB.id!=-1)
	{
		if (schnitt(segA.line, segB.line))
		{
			Point AB = schnittPunkt(segA.line, segB.line);
			Event intersectAB = Event(segA.id, segB.id, AB.x, AB.y);
			
				eventQueue.insert(intersectAB);
		}
	}

}

void handleIntersectionEvent(Event _e) {
	outputIntersections.push_back(_e);

	sweepLine.swap(_e.idxEnd, _e.idxStart);
	LineSegment E1 = sweepLine.getSegment(_e.idxStart);
	LineSegment E2 = sweepLine.getSegment(_e.idxEnd);
	if (E1.id != -1 && E2.id != -1)
	{



		if (E1.line.q.y > E2.line.q.y)
		{
			//sorge dafür dass E2 der name für das obere segment ist
			LineSegment E = E1;
			E1 = E2;
			E2 = E;
		}

		//E1 ist oben nach dem swap
		LineSegment segA = sweepLine.getAbove(E2);

		if (segA.id != -1)
		{
			//schnitt existiert
			if (schnitt(E2.line, segA.line))
			{
				if (true)
				{
					Point EA = schnittPunkt(E2.line, segA.line);
					Event intersectEA = Event(E2.id, segA.id, EA.x, EA.y);

					eventQueue.insert(intersectEA);


				}

			}
		}
		LineSegment segB = sweepLine.getBelow(E1);
		//if SegB exists
		if (segB.id != -1)
		{
			//schnitt existiert
			if (schnitt(E1.line, segB.line))
			{
				Point EB = schnittPunkt(E1.line, segA.line);
				Event intersectEB = Event(E1.id, segA.id, EB.x, EB.y);

				eventQueue.insert(intersectEB);

			}
		}
	}
	else
	{
		cout << "Error segments deleted before intersection" << endl;
	}
}