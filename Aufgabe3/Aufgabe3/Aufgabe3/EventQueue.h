#pragma once
#include "Event.h"
#include <vector>
#include "Linie.h"
#include <algorithm>

class EventQueue
{
private:
	std::vector<Event> eventQueue;
public:
	EventQueue(std::vector <Line> l);
	EventQueue();
	~EventQueue();
	void insert(Event _e);
	void fill(std::vector <Line> l);
	void sort();
	int size();
	Event back();
	Event front();
	void remove(int index);



	
};

