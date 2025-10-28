#include <iostream>
using namespace std;

#include "bookingsystem.hpp"
#include "booking.hpp"
#include "slotRange.hpp"
#include "week.hpp"


void reserve(BookingSystem& sys)
{
	int week, start, end;
	cout << "type in the week and slots you want (week, start, end)" << endl;
	cin >> week >> start >> end;
	SlotRange r(week, start, end);
	if (sys.canReserve(week,r) == false)
	{
		cout << "week number is invalid" << endl;
		return;
	}
	cout << "enter your name" << endl;
	string name;
	cin >> name;
	int id = sys.addBooking(week, r, name);
	if (id >= 0)
		sys.checkWeek(week);


}

void query(BookingSystem& sys)
{
	int id=0;
	cout << "enter booking id:" << endl;
	cin >> id;
	sys.queryBooking(id);

}

void Cancel(BookingSystem& sys)
{
	int id=0;
	cout << "enter booking id to cancel:" << endl;
	cin >>id;

	if (sys.cancelBooking(id))
	{
		cout << "selection is cancelled" << endl;
	}
	else
		cout << "selection is not cancelled" << endl;

}

void check(BookingSystem& sys)
{
	int week=0;
	cout << "enter the week you wanna check" << endl;
	cin >> week;
	sys.checkWeek(week);
}



int main()
{
	BookingSystem sys; //Create BookingSystem object.
	bool Status = true;

	while (Status)  //Loop: Read commands ("reserve ", "query ", "cancel ", "check ", "exit").
	{
		int op=0;
		cout << "choose your operation: 1.reserve, 2.query, 3.cancel, 4.check, 5.exit" << endl;
		cin >> op;
		if (op != 1 && op != 2 && op != 3 && op != 4 && op != 5)
		{
			break;
		}
		if (op == 1)
			reserve(sys);
		if (op == 2)
			query(sys);
		if (op == 3)
			Cancel(sys);
		if (op == 4)
			check(sys);
		if (op == 5)//i assume this is like exit the program to desktop ish operation 
			break;
	}
	return 0;
}//there is a problem when you enter 3, basically i want it to cout id is no longer available, but it types before saying the id is cancelled