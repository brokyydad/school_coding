//slotRange.cpp to implement your class
#include "slotRange.hpp"
#include "week.hpp"
SlotRange::SlotRange()
{
	week = 0;
	beginSlot = 1;
	endSlot = 1;
}
//contructor
SlotRange::SlotRange(int w, int start, int end)
{
	week = w;
	beginSlot = start;
	endSlot = end;
}
//getter setter
int SlotRange::getWeek() const
{
	return week;
}

void SlotRange::setWeek(int w)
{
	week = w;
}


int SlotRange::getBeginSlot() const
{
	return beginSlot;
}

void SlotRange::setBeginSlot(int newBegin)
{
	beginSlot = newBegin;
}

int SlotRange::getEndSlot() const
{
	return endSlot;
}

void SlotRange::setEndSlot(int newEnd)
{
	endSlot = newEnd;
}
//is valid
bool SlotRange::isValid() const
{
	

	for (int i = 0; i < numMaintenanceWeeks; i++)
	{
		if (week == maintenanceWeeks[i])
		{
			cout << "The slot is inValid" << endl;
			return false;
		}
	}
	for (int i = 0; i < numPeakWeeks; i++)
	{
		if (week == peakWeeks[i])
		{
			cout << "The slot is inValid" << endl;
			return false;
		}
	}

	if (beginSlot < 0 || endSlot>23 || beginSlot >= endSlot)
	{
		cout << "The slot is inValid" << endl;
		return false;
	}
	int duration = endSlot - beginSlot + 1;

	if (duration % 2 != 0)
	{
		cout << "The slot is inValid" << endl;
		return false;
	}

	

	return true;
}

void SlotRange::output(ostream& outs) const
{
	if (isValid() == false)
	{
		outs << "This is invalid" << endl;
	}
	else
	{
		outs << "The slot of week " << week << " is valid from " << beginSlot << " to " << endSlot << endl;
	}
}