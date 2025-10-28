#include "bookingsystem.hpp"
using namespace std;

//define global const peakWeeks, e.g. 22–24, 35–37, 51–52


BookingSystem::BookingSystem()
{
	//week
	for (int i = 0; i < 52; i++)
	{
		weeks[i] = Week(i);//default constructor from lab 1
	}
	//booking count 
	bookingCount = 0;
		
}

BookingSystem::BookingSystem(const Booking initialBookings[], int count)
{
	bookingCount = 0;
	for (int i = 0; i < 52; i++)
	{
		weeks[i] = Week(i);
	}
	for (int i = 0; i < 200; i++) {
		if (i >= count) 
			break;
		if (bookingCount >= 200)
		{ 
			cout << "exceed 200 limit" << endl;
			break;
		}

		const Booking& b = initialBookings[i];
		int wk = b.getWeek().getWeek();//same name from lab 1 1st return a week object 2nd return the int week under the week object
		// i know the format is confusing but i somehow had the same name for 2 assignment 

		SlotRange r = b.getSr();

		if (canReserve(wk, r)) 
		{
			bookings[bookingCount++] = b;
			for (int s = r.getBeginSlot(); s <= r.getEndSlot(); s++) 
			{
				weeks[wk].setReserved(s);
			}
		}
		else
		{
			cout << "skip " << b.getBookingID() << endl;
		}
	}
}

bool BookingSystem::canReserve(int weekNum, const SlotRange& range) const
{
	if (weekNum < 0 || weekNum>51)
	{
		cout << "invalid week" << endl;
		return false;
	}
	if (range.isValid() == false)
		return false;
	if (range.getWeek() != weekNum)
		return false;
	int start = range.getBeginSlot();
	int end = range.getEndSlot();
	if (start < 0 || end>23 || end < start)//validation
		return false;
	if (((end - start + 1) % 2) != 0)// even numbers 
		return false;

	for (int i = 0; i < numPeakWeeks; i++) 
	{
		if (weekNum == peakWeeks[i]) 
			return false;
	}


	for (int i = 0; i < bookingCount; i++)
	{
		if (bookings[i].getBookingID() > 0)
		{
			if (bookings[i].getWeek().getWeek() != weekNum) //again same name from lab1
				continue;
			SlotRange newSlotRange = bookings[i].getSr();
			int newStart = newSlotRange.getBeginSlot();
			int newEnd = newSlotRange.getEndSlot();
			if (start <= newEnd && end >= newStart)
				return false;
		}
	}
	for (int i = start; i <= end; i++)
	{
		if (weeks[weekNum].getReserved(i))
			return false;
	}
	return true;
}

int BookingSystem::addBooking(int weekNum, const SlotRange& range, string name)
{
	if (!canReserve(weekNum, range)||bookingCount>199)
	{
		cout << "This week or slot is invalid" << endl;
		return -1;
	}
	int start = range.getBeginSlot();
	int end = range.getEndSlot();

	Booking b(weekNum, start, end, name);
	bookings[bookingCount++] = b;

	for (int i = start; i <= end; i++)
	{
		weeks[weekNum].setReserved(i);

	}

	cout << "The booking id is " << b.getBookingID() << endl;
	return b.getBookingID();
}

bool BookingSystem::queryBooking(int bookingID) const
{
	if (bookingID <= 0)
	{ 
		cout << "invalid id "; 
		return false;
	}

	for (int i = 0; i < bookingCount; i++) 
	{
		if (bookings[i].getBookingID() == bookingID)
		{
			bookings[i].print(cout);

			return true;
		}
	}

	cout << "invalid id "<<endl;
	return false; 
}

bool BookingSystem::cancelBooking(int bookingID)
{
	if (bookingID <= 0) {
		cout << "invalid id" << endl;
		return false;
	}

	int index = -1;
	for (int i = 0; i < bookingCount; i++) {
		if (bookings[i].getBookingID() == bookingID) { index = i; break; }
	}
	if (index == -1) {
		cout << "Booking ID not found" << endl;
		return false;
	}

	int wk = bookings[index].getWeek().getWeek();
	bookings[index].setBookingId(-1);

	weeks[wk] = Week(wk);// reset week to all-free
	for (int i = 0; i < bookingCount; i++) 
	{
		if (bookings[i].getBookingID() > 0 && bookings[i].getWeek().getWeek() == wk)
		{
			SlotRange r2 = bookings[i].getSr();
			for (int s = r2.getBeginSlot(); s <= r2.getEndSlot(); s++)
			{
				weeks[wk].setReserved(s);
			}
		}
	}

	cout << "Canceled " << bookingID << endl;
	return true;
}

void BookingSystem::checkWeek(int weekNum) const
{
	if (weekNum < 0 || weekNum > 51) {
		cout << "invalid week" << endl;
		return;
	}

	cout << "Week " << weekNum << " status:" << endl;
	cout << "Reserved slots: ";
	bool anyR = false;/// reservved slots 
	for (int s = 0; s <= 23; s++)
	{
		if (weeks[weekNum].getReserved(s))
		{ 
			cout << s << " "; 
			anyR = true;
		}
	}
	if (anyR==false)
		cout << "none" << endl;

	cout << "Free slots are: ";
	bool anyF = false;//any freee slots 
	for (int s = 0; s <= 23; s++)
	{
		if (!weeks[weekNum].getReserved(s))
		{
			cout << s << " ";
			anyF = true;
		}
	}
	if (anyF==false) 
		cout << "none";
}
