#include "booking.hpp"
#include<iostream>
using namespace std;

int Booking::index = 1;

Booking::Booking()
{

    week = Week(0);
    range = SlotRange(1, 0, 1);
    customerName = "N/A"; 
}

Booking::Booking(int weekNum, int beginSlot, int endSlot, string name)
{
    Week tempWeek(weekNum);
    SlotRange tempSr(weekNum, beginSlot, endSlot);
    if (!tempWeek.isValid()||!tempSr.isValid())
    {
        cout << "Invalid week or slot range" << endl;
        bookingID = 0;
        return;
    }
    else
    {
        week = tempWeek;
        range = tempSr;
        customerName = name;
        bookingID = index++;
    }
}

int Booking::getBookingID() const
{
    return bookingID;
}

Week Booking::getWeek() const
{
    return week;
}

SlotRange Booking::getSr() const
{
    return range;
}

string Booking::getCr() const
{
    return customerName;
}

void Booking::setBookingId(int Id)
{
    if (Id < 200 && Id >= 0)
        bookingID = Id;
    else
        cout << "This Id is invalid" << endl;
}

void Booking::setWeek(Week w)
{
    if(w.isValid())
        week = w;
    else
        cout << "This week is invalid" << endl;
}

void Booking::setSr(SlotRange r)
{
    if(r.isValid())
        range = r;
    else
        cout << "This SlotRange is invalid" << endl;
}

void Booking::setString(string s)
{
    customerName = s;
}

bool Booking::isConflicting(const Booking& other)
{
    int start1 = range.getBeginSlot();
    int end1 = range.getEndSlot();
    int start2 = other.range.getBeginSlot();
    int end2 = other.range.getEndSlot();
    //same week
    //overlap slots
    if (week.getWeek() != other.week.getWeek())
        return false;
    if (start1<=end2 && end1>=start2)
        return true;
    else
        return false;
}

void Booking::print(std::ostream& os) const
{
    os << "Booking id is " << bookingID << endl;
    os << "Name is " << customerName << endl;
    os << "Week is " << week.getWeek() << endl;
    os << "Slots are " << range.getBeginSlot() << " to " << range.getEndSlot() << endl;
}
