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
int schnitte = 0, kolinear = 0, rest = 0, kolinar_mit_überlappung = 0;


bool istLinie(Linie linie);

void readLines(string filepath);

bool sortingCondition(Event i, Event j);

float ccw(Point p, Point q, Point r);

bool überlappungstest(Point p1, Point p2, Point q1, Point q2);

bool schnitt(Point p1, Point p2, Point q1, Point q2);

bool schnitt(Linie l1, Linie l2);

void handleStartEvent(Event _e);

void handleEndEvent(Event _e);

void handleIntersectionEvent(Event _e);

