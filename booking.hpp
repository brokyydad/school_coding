#ifndef BOOKING_HPP
#define BOOKING_HPP

#include <iostream>
#include "week.hpp"
#include "slotRange.hpp"
using namespace std;

class Booking {
private:
    int bookingID;
    Week week;
    SlotRange range;
    string customerName;
    static int index;

public:
    //constructors
    Booking();
    Booking(int weekNum, int beginSlot, int endSlot, string name);
    //getter 
    int getBookingID() const;
    Week getWeek() const;
    SlotRange getSr() const;
    string getCr() const;
    //setter
    void setBookingId(int Id);
    void setWeek(Week w);
    void setSr(SlotRange r);
    void setString(string s);
    //customized function
    bool isConflicting(const Booking& other);
    //output
    void print(std::ostream& os) const;


};

#endif
