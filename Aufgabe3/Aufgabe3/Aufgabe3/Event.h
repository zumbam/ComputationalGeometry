#pragma once
#include <string>
#include <iostream>
#include <iomanip> 
/*
idx repräsentiert welche Linie es ist
if idxStart != -1 => Event= Start of Line
if idxEnd != -1 => Event= End of Line
if both != -1 => Event= Intersection
if both -1 => Event uninitialized/Error
*/
class Event
{

public:
	//-1 if not used
	int idxStart;
	//-1 if not used
	int idxEnd;

	float x;
	float y;

	Event();
	/*
	if idxStart != -1 => Event= Start of Line
	if idxEnd != -1 => Event= End of Line
	if both != -1 => Event= Intersection
	if both -1 => Event uninitialized/Error
	*/
	Event(int IdxStart, int IdxEnd, float X, float Y);
	~Event();

	
	void print();	
};