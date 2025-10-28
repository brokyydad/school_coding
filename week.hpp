//header file week.hpp to declare your class
#ifndef WEEK_HPP
#define WEEK_HPP

#include <iostream>
#include"slotRange.hpp"
using namespace std;


const int maintenanceWeeks[] = {0, 12, 25, 38, 51};
const int numMaintenanceWeeks = 5;

const int peakWeeks[] = { 21,22, 23,34,35,36,50,51 };//i used 0-51 not 1-52 from lab1
const int numPeakWeeks = 8;




class Week {
private:
	int week;
	bool reserved[24];

public:
	Week();
	Week(int week);
	//getter setter
	int getWeek() const;
	void setWeek(int week) ;
	bool getReserved(int index) const;
	void setReserved(int index);
	friend bool equal(const Week& w1, const Week& w2); // access to private
	// a done 

	bool isMaintenance() const;
	// b done 

	bool isValid() const;
	// c done 

	void output(ostream& outs) const;
	// d done 

	void printFreeSlots() const;
	void printReservedSlots() const;
	//e 
	bool isPeak() const;
	//lab2 added function
	void markReserved(const SlotRange& range, bool status);
};


#endif