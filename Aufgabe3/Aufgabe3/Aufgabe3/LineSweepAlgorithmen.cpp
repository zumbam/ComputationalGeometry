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
	lines.clear();

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
		cout << "read " << lines.size() << " lines" << endl;

	}
	else
	{
		std::cout << "file not found" << std::endl;
	}
	file.close();
}


int main()
{
	init();

	readLines("data/s_1000_1.dat");

	RawAlgorithm();
	cout << "Output intersections: " << outputIntersections.size() << endl;
	SDLbackground();
	for (int i = 0; i < lines.size(); i++)
	{
		SDLdraw(lines[i], 2);
	}
	for (int i = 0; i < outputIntersections.size(); i++)
	{
		SDLdraw({ outputIntersections.eventQueue[i].x,
			outputIntersections.eventQueue[i].y }, 7, 1);
	}
	SDLrender();
	outputIntersections = EventQueue();

	cout << "SweepLine Algorithm" << endl;
	SweepLineAlgorithm();
	cout << "Output intersections: " << outputIntersections.size() << endl;




	int i;
	std::cin >> i;
	close();
	return 0;
}



void SweepLineAlgorithm() {
	sweepLine = SweepLine();
	eventQueue = EventQueue();
	auto start_time = std::chrono::high_resolution_clock::now();
	//Linien richtig setzen und sortieren
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

#ifdef INFO
		e.print();
#endif // INFO

//drawing stuff
		SDLclear();
		SDLrenderTexture();

		SDLdraw(Point(e.x, e.y), 3, 3);
		SDLdraw(Line({ e.x,1080 }, { e.x, 0 }), 6);



		for (int i = 0; i < sweepLine.sweepLine.size(); i++)
		{
			SDLdraw(sweepLine.sweepLine[i].line, 4);
		}
		SDLrender();
		if (e.idxEnd == -1 && e.idxStart == -1)
		{
			//error/uninitalized
			std::cout << "FATAL ERROR: Event uninitialized";
			break;
		}
		else if (e.idxEnd != -1 && e.idxStart != -1)
		{


			SDLbackground();
			SDLdraw({ e.x,e.y }, 5, 1);



			//intersection event
			handleIntersectionEvent(e);

		}
		else if (e.idxEnd == -1)
		{
			//startevent
			handleStartEvent(e);

		}
		else if (e.idxStart == -1)
		{
			//endEvent
			handleEndEvent(e);
		}

		//remove first element from event queue
		eventQueue.remove(e);
	}


	auto end_time = std::chrono::high_resolution_clock::now();
	auto time = end_time - start_time;
	std::cout << "dauer " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(time).count() << "ms" << endl;
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
			Point EB = schnittPunkt(segE.line, segB.line);
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
	if (segA.id != -1 && segB.id != -1)
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
	//add to output intersections if not already existing
	if (outputIntersections.find(_e) == -1)
	{
		outputIntersections.push_back(_e);




		sweepLine.swap(_e.idxEnd, _e.idxStart);
		LineSegment E1 = sweepLine.getSegment(_e.idxStart);
		LineSegment E2 = sweepLine.getSegment(_e.idxEnd);
		if (E1.id != -1 && E2.id != -1)
		{
			//E1 und E2 existieren


			if (sweepLine.getAbove(E2).id == E1.id)
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
					Point EB = schnittPunkt(E1.line, segB.line);
					Event intersectEB = Event(E1.id, segB.id, EB.x, EB.y);


					eventQueue.insert(intersectEB);


				}
			}
		}
		else
		{
			cout << "Error segments deleted before intersection" << endl;
		}
	}
	else
	{

#ifdef INFO
		cout << "Intersection already exists in output ";
		_e.print();
#endif // INFO

	}
}

//alle gegen alle Testen
void RawAlgorithm()
{
	auto start_time = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < lines.size(); i++)
	{
		for (int j = i + 1; j < lines.size(); j++)
		{
			if (schnitt(lines[i], lines[j])) {
				Point p = schnittPunkt(lines[i], lines[j]);
				Event intersection(i, j, p.x, p.y);
				if (outputIntersections.find(intersection) == -1)
				{
					outputIntersections.push_back(intersection);
				}
				else
				{
#ifdef INFO
					cout << "Intersection already exists in output ";
					intersection.print();
#endif // INFO

				}

			}
		}
		if (i % 1000 == 0 && i != 0)
		{
#ifdef INFO

			std::cout << float(float(i) / lines.size()) * 100 << "%" << endl;
#endif // INFO

		}


	}

	auto end_time = std::chrono::high_resolution_clock::now();
	auto time = end_time - start_time;
	std::cout << "dauer " <<
		std::chrono::duration_cast<std::chrono::milliseconds>(time).count() << "ms" << endl;

}