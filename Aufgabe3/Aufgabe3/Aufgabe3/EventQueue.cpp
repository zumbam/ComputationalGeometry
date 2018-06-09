#include "stdafx.h"
#include "EventQueue.h"




EventQueue::EventQueue(std::vector<Line> _l)
{
	fill(_l);
	sort();
}

EventQueue::EventQueue()
{
}

EventQueue::~EventQueue()
{
}


void EventQueue::insert(Event _e)
{
	for (int i = 0; i < size(); i++)
	{
		if (_e.x>eventQueue[i].x)
		{
			eventQueue.insert(eventQueue.begin() + i, _e);
			return;
		}
	}
	std::cout << "ERROR could not insert EVENT: " <<std::endl;
	_e.print();
}

void EventQueue::fill(std::vector<Line> _l)
{
	for (int i = 0; i < _l.size(); i++)
	{
		Event e1 = Event(-1, -1, _l[i].p.x, _l[i].p.y);
		Event e2 = Event(-1, -1, _l[i].q.x, _l[i].q.x);
		//prüfe was davon der Anfangs und Endpunkt ist
		if (e1.x < e2.x) {
			e1.idxStart = i;
			e2.idxEnd = i;
		}
		else
		{
			e1.idxEnd = i;
			e2.idxStart = i;
		}
		eventQueue.push_back(e1);
		eventQueue.push_back(e2);
	}
}

void EventQueue::sort()
{
	//sort event Queue by x
	std::sort(eventQueue.begin(), eventQueue.end(), [](const Event i, const Event j)
	{
		
			//highest element at end
			return i.x < j.x;
		
	});
}

int EventQueue::size()
{
	if (eventQueue.size()<0)
	{
		std::cout << "eventQueue<0!" << std::endl;
		return 0;
	}
	return eventQueue.size();
}

Event EventQueue::back()
{
	return eventQueue.back();
}

Event EventQueue::front()
{
	return eventQueue.front();
}

void EventQueue::remove(int _i)
{
	eventQueue.erase(eventQueue.begin() + _i);
}







