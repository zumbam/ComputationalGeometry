#include "stdafx.h"
#include "EventQueue.h"


EventQueue::EventQueue()
{
}

EventQueue::~EventQueue()
{
}


void EventQueue::insert(Event _e)
{
	if (find(_e) == -1)
	{


		cout << "INSERTING: ";
		_e.print();
		if (eventQueue.size() == 0)
		{
			eventQueue.push_back(_e);
		}
		else
		{
			for (int i = eventQueue.size()-1; i >= 0; i--)
			{
				if (_e.x >= eventQueue[i].x)
				{

					eventQueue.insert(eventQueue.begin() + i, _e);
					return;
				}
			}
			if (_e.x>=0)
			{
				eventQueue.insert(eventQueue.begin(), _e);
				return;
			}
			else
			{
				std::cout << "ERROR could not insert EVENT: x <0 " << std::endl;
				_e.print();
			}
			
		}
	}
	else
	{
		cout << "event already in queue" << endl;
	}
}

int EventQueue::find(Event _e) {
	for (int i = 0; i < eventQueue.size(); i++)
	{
		if (_e.idxEnd == -1 && _e.idxStart == -1)
		{
			//error/uninitalized
			std::cout << "ERROR: Event uninitialized should not be in event queue" << endl;
			return -1;
		}
		else if (_e.idxEnd != -1 && _e.idxStart != -1)
		{
			//intersection event
			if ((_e.idxStart == eventQueue[i].idxStart
				&&_e.idxEnd == eventQueue[i].idxEnd)
				|| (_e.idxStart == eventQueue[i].idxEnd
					&&_e.idxEnd == eventQueue[i].idxStart))
			{
				return i;
			}

		}
		else if (_e.idxEnd == -1)
		{
			//startevent
			if (_e.idxStart == eventQueue[i].idxStart)
			{
				return i;
			}

		}
		else
		{
			if (_e.idxEnd == eventQueue[i].idxEnd)
			{
				return i;
			}

		}
	}
	return -1;
}

void EventQueue::fill(std::vector<Line> _l)
{
	eventQueue.clear();
	for (int i = 0; i < _l.size(); i++)
	{
		Event e1 = Event(-1, -1, _l[i].p.x, _l[i].p.y);
		Event e2 = Event(-1, -1, _l[i].q.x, _l[i].q.y);
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

bool EventQueue::empty()
{
	if (eventQueue.size() < 0)
	{
		std::cout << "eventQueue<0!" << std::endl;
		return true;
	}
	if (eventQueue.size()>0)
	{
		return false;
	}
	else
	{
		return true;
	}
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







