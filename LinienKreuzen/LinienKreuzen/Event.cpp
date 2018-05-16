#include "stdafx.h"
#include "Event.h"


Event::Event()
{
	idxStart = -1;
	idxEnd = -1;
	x = -1.0f;
	y = -1.0f;
}

Event::Event(int _idxStart, int _idxEnd, float _x, float _y) {
	idxStart = _idxStart;
	idxEnd = _idxEnd;
	x = _x;
	y = _y;
}



Event::~Event()
{
}
