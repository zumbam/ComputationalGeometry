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

vector <Line> lines;

EventQueue eventQueue;
SweepLine sweepLine;
vector <Event> outputIntersections;



bool istLinie(Line linie);

bool istVertical(Line line);

void readLines(string filepath);

void handleStartEvent(Event _e);

void handleEndEvent(Event _e);

void handleIntersectionEvent(Event _e);

