//week.cpp to implement your class
#include "week.hpp"
using namespace std;

Week::Week()
{
	week = 0;
}

Week::Week(int w)
{
	week = w;
	for (int i = 0; i < 24; i++)
	{
		reserved[i] = false;
	}
}

int Week::getWeek() const
{
	return week;
}

void Week::setWeek(int newWeek)
{
	
	week = newWeek;
}

bool Week::getReserved(int index) const
{
	if (index < 0 || index > 23)
	{
		cout << "This is invalid slot" << endl;

		return false;
	}
	return reserved[index];
}

void Week::setReserved(int index)
{
	if(index>=0&&index<=23)
		reserved[index] = true;
	else
	{
		cout << "This is invalid slot" << endl;
		return;
	}
}

bool equal(const Week& w1, const Week& w2)
{
	if (w1.week == w2.week)
		return true;
	else
		return false;
}

bool Week::isMaintenance() const
{
	for (int i = 0; i < numMaintenanceWeeks; i++)
	{
		if (equal(*this, Week(maintenanceWeeks[i])))
			return true;
	}
	return false;
}


bool Week::isValid() const
{
	if (week >= 0 && week <= 51)
		return true;
	else
	{
		cout << " this week is not valid" << endl;
		return false;
	}
}

void Week::output(ostream& outs) const
{
	outs << "WEEK " << week << endl;
	if (isValid() == false)
	{
		outs << " is not valid" << endl;
		return ;
	}
	if (isMaintenance() == true)
		outs << " is under maintenance" << endl;
	else if (isPeak() == true)
		outs << " is peak week" << endl;
	else
		outs << " is a regular week" << endl;
	
	bool noneReserved = true;
	for (int i = 0; i < 24; i++)
	{
		if (reserved[i] == true)
		{
			outs << "Slot " << i << "–" << i + 1 << " is reserved" << endl;
			noneReserved = false;
		}
	}

	if (noneReserved == true)
		outs << "nothing is reserved" << endl;
}
		

void Week::printFreeSlots() const
{
	if (!isValid() || isMaintenance() || isPeak())
	{
		cout << "No free spots" << endl;
		return;
	}
	bool noFreeSpots = true;
	for (int i = 0; i < 24; i++)
	{
		if (reserved[i] == false) 
		{
			cout << "Slot " << i << "-" << i + 1 << " is free" << endl;
			noFreeSpots = false;
		}
	}

	if (noFreeSpots == true)
		cout << "no free spots this week" << endl;

}

void Week::printReservedSlots() const
{

	if (!isValid())
	{
		cout << "no reserved spots" << endl;
		return;
	}
	bool noReservedSpots = true;
	for (int i = 0; i < 24; i++)
	{
		if (reserved[i] == true)
		{
			cout << "Slot " << i << " " << "–" << i + 1 <<" is reserved" << endl;
			noReservedSpots = false;
		}
	}

	if (noReservedSpots == true)
		cout << "no reserved spots this week" << endl;

}

bool Week::isPeak() const
{
	for (int i = 0; i < numPeakWeeks; i++) 
	{
		if (week == peakWeeks[i]) 
			return true;
	}
	return false;
}

void Week::markReserved(const SlotRange& range, bool status)
{
	
	int start = range.getBeginSlot();
	int end = range.getEndSlot();
	if (start < 0 || end>23 || start > end)
		return;

	for (int i = start; i <= end; i++)
	{
		reserved[i] = status;
	}


}
