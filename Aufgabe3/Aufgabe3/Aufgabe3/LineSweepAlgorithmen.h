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

vector <Line> lines;

EventQueue eventQueue;
vector <Line> sweepLine;
vector <Event> outputIntersections;



bool istLinie(Line linie);

bool istVertical(Line line);

void readLines(string filepath);


void handleStartEvent(Event _e);

void handleEndEvent(Event _e);

void handleIntersectionEvent(Event _e);

