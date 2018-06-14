#pragma once
#include "Event.h"
#include <vector>
#include "Linie.h"
#include <algorithm>

//Klasse für die Event Queue
class EventQueue
{
public:
	/*Datenstruktur der EventQueue
	kann in Zukunft durch anderer struktur ersetzt werden*/
	std::vector<Event> eventQueue;

	EventQueue();
	~EventQueue();
	//fügt ein Event am ende hinzu
	void push_back(Event _e);
	//fügt ein Event entsprechend der x koordinate ein
	void insert(Event _e);
	//findet ein Event über seine indices (position irrelevent)
	int find(Event _e);
	//füllt die Event Queue neu mit Werten
	void fill(std::vector <Line> l);
	//sortiert die EventQueue nach x Werten
	void sort();
	//gibt aus ob die Queue leer ist
	bool empty();
	//gibt das letzte element aus
	Event back();
	//gibt das erste element aus
	Event front();
	//finds element end removes it
	void remove(Event _e);
	//gets the size
	int size();


	



	
};

