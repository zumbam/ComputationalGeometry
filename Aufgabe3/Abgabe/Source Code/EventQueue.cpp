#include "stdafx.h"
#include "EventQueue.h"


EventQueue::EventQueue()
{
}

EventQueue::~EventQueue()
{
}

void EventQueue::push_back(Event _e)
{
	eventQueue.push_back(_e);
}

void EventQueue::insert(Event _e)
{
	if (find(_e) == -1)
	{


#ifdef INFO
		cout << "INSERTING: ";
		_e.print();
#endif // INFO

		if (eventQueue.size() == 0)
		{
			eventQueue.push_back(_e);
		}
		else
		{
			for (int i = 0; i <eventQueue.size() ; i++)
			{
				if (_e.x <= eventQueue[i].x)
				{

					eventQueue.insert(eventQueue.begin() + i, _e);
					return;
				}
			}
			if (_e.x >= 0)
			{
				//higly unlikly even impossible
				eventQueue.push_back( _e);
				return;
			}
			else
			{
				std::cout << "ERROR could not Insert Event not Initialized: x <0 :";
				_e.print();
			}

		}
	}
	else
	{
#ifdef INFO
		cout << "event already in queue" << endl;		
#endif // INFO


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
			bool normal = _e.idxStart == eventQueue[i].idxStart
				&&_e.idxEnd == eventQueue[i].idxEnd;

			bool inverted = (_e.idxStart == eventQueue[i].idxEnd
				&&_e.idxEnd == eventQueue[i].idxStart);
			if (normal || inverted)

			{
				return i;
			}

		}
		else if (_e.idxEnd == -1)
		{
			//startevent
			if (_e.idxStart == eventQueue[i].idxStart
				&& eventQueue[i].idxEnd == -1)
			{
				return i;
			}

		}
		else
		{
			if (_e.idxEnd == eventQueue[i].idxEnd
				&& eventQueue[i].idxStart == -1)
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
		//p == startEvent q ==endevent
		Event e1 = Event(i, -1, _l[i].p.x, _l[i].p.y);
		Event e2 = Event(-1, i, _l[i].q.x, _l[i].q.y);
		//prüfe was davon der Anfangs und Endpunkt ist
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
	if (eventQueue.size() > 0)
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

void EventQueue::remove(Event _e)
{

	int i = find(_e);
	if (i >= 0)
	{
		eventQueue.erase(eventQueue.begin() + i);
	}
	else
	{
		cout << " could not remove Event: ERROR i<0" << endl;
	}
}

int EventQueue::size()
{
	return eventQueue.size();
}







