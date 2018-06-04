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

bool istLinie(Linie linie);

void readLines(string filepath);

bool sortingCondition(Event i, Event j);

void handleStartEvent();

void handleEndEvent();

void handleIntersectionEvent();
