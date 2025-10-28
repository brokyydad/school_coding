#ifndef BOOKINGSYSTEM_HPP
#define BOOKINGSYSTEM_HPP

#include <iostream>
#include "booking.hpp"
#include "week.hpp"
#include "slotRange.hpp"
using namespace std;

class BookingSystem {
private:
    Booking bookings[200];
    int bookingCount;
    Week weeks[52];

public:
    BookingSystem();
    BookingSystem(const Booking initialBookings[], int count);

    bool canReserve(int weekNum, const SlotRange& range) const;
    int addBooking(int weekNum, const SlotRange& range, string name);
    bool queryBooking(int bookingID) const;
    bool cancelBooking(int bookingID);
    void checkWeek(int weekNum) const;
};

#endif
