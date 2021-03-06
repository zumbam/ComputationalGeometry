#include <iostream>
#include <sstream>
#include "Schnitte.h"
#include <vector>
#include <fstream>
#include <chrono>
#include "Event.h"
#include <algorithm>
#include "EventQueue.h"
#include "LineSegment.h"
#include "SweepLine.h"
#include "Vizualizer.h"

struct TimeTable
{
	string filename;
	float rawTime;
	float sweepLineTime;
};



#define INFO
vector <TimeTable> timeTable;
vector <Line> lines;

EventQueue eventQueue;
SweepLine sweepLine;
EventQueue outputIntersections;

bool istLinie(Line linie);

bool istVertical(Line line);

void readLines(string filepath);

int main();

void RawAlgorithm();

void SweepLineAlgorithm();

void handleStartEvent(Event _e);

void handleEndEvent(Event _e);

void handleIntersectionEvent(Event _e);

