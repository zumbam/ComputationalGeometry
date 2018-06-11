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


void Event::print()
{
	using namespace std;
	string type;
	if (idxEnd==-1&&idxStart==-1)
	{
		//error/uninitalized
		type = "err/ uninitializeed";
	}
	else if (idxEnd!=-1&&idxStart!=-1)
	{
		//intersection event
		type = "intersection";
	}
	else if (idxEnd==-1)
	{
		//startevent
		type = "start";
	}
	else
	{
		//endEvent
		type = "end";
	}

	cout <<"EVENT \t" <<type <<"\t"<<idxStart<<"  "<<idxEnd <<" x " << std::fixed <<setprecision(7)<< x<< " y " << setprecision(7) << y << endl;
}
