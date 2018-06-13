#include "stdafx.h"
#include "SweepLine.h"


SweepLine::SweepLine()
{
}

SweepLine::~SweepLine()
{
}

void SweepLine::insert(LineSegment _lineSegment)
{
	if (sweepLine.size() == 0)
	{
		sweepLine.push_back(_lineSegment);
	}
	else
	{
		for (int i = sweepLine.size()-1; i >=0; i--)
		{
			Point schnitt = schnittPunkt(sweepLine[i].line, Line(_lineSegment.line.p,
				{ _lineSegment.line.p.x,1000 }));
			
			float y = sweepLine[i].line.getYat(_lineSegment.line.p.x);
			if (abs(schnitt.y-y)>0.0001f)
			{
	#ifdef _DEBUG
				cout << "Error: Calculating y went wrong" << endl;
	#endif // _DEBUG
				
			}
			if (_lineSegment.line.p.y >= y)
			{
				sweepLine.insert(sweepLine.begin() + i, _lineSegment);
				return;
			}
		}
		//
		//cout << "ERROR couldnt insert into sweepLine" << endl;
		sweepLine.insert(sweepLine.begin(), _lineSegment);
		return;
	}

}

void SweepLine::remove(LineSegment _lineSegment)
{
	int i = getSegmentPosition(_lineSegment);
	if (i != -1)
	{
		sweepLine.erase(sweepLine.begin() + i);
	}
#ifdef _DEBUG
#ifdef INFO

	cout << "Removed LineSegment index:" << _lineSegment.id << endl;
#endif // INFO

#endif // _DEBUG

}

void SweepLine::swap(int i1, int i2)
{
	int pos1 = getSegmentPosition(i1);
	int pos2 = getSegmentPosition(i2);
	if (pos1 != -1 && pos2 != -1)
	{
		LineSegment t = sweepLine[pos1];
		sweepLine[pos1] = sweepLine[pos2];
		sweepLine[pos2] = t;
	}
	else
	{
		cout << "Swapping not possible one or more elements not found"<<endl;
	}
}

LineSegment SweepLine::getSegment(int _id)
{
	int i = getSegmentPosition(_id);
	if (i!=-1)
	{
		return sweepLine[i];
	}
	else
	{
		cout << "ERROR: could not get Segment" << endl;
		return LineSegment();
	}
	
}


LineSegment SweepLine::getAbove(LineSegment _lineSegment)
{
	int i = getSegmentPosition(_lineSegment);
	if (i > 0)
	{
		return sweepLine[i - 1];
	}
	else
	{
		//LineSegment is First;
		//cout << "LineSegement is first in SweepLine" << endl;
		return LineSegment();
	}
}

LineSegment SweepLine::getBelow(LineSegment _lineSegment)
{
	int i = getSegmentPosition(_lineSegment);
	if (i < sweepLine.size() - 1)
	{
		return sweepLine[i + 1];
	}
	else
	{
		//LineSegment is First;
		//cout << "LineSegement is last in SweepLine" << endl;
		return LineSegment();
	}
}

int SweepLine::getSegmentPosition(LineSegment _lineSegment)
{
	return getSegmentPosition(_lineSegment.id);
}

int SweepLine::getSegmentPosition(int _id)
{
	if (_id >= 0)
	{
		for (int i = 0; i < sweepLine.size(); i++)
		{
			if (sweepLine[i].id == _id)
			{
				return i;
			}

		}
		//LineSegment not found;
		cout << "ERROR: LineSegment not Found! from:" << _id << endl;
		return -1;
	}
	cout << "index negative" << _id << endl;
	return -1;
}




