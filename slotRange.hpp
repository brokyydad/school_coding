//header file slotRange.hpp to declare your class
#ifndef SLOTRANGE_HPP
#define SLOTRANGE_HPP

#include <iostream>
using namespace std;


class SlotRange 
{
	private:
		int week;
		int beginSlot;
		int endSlot;

	public:
		SlotRange();
		SlotRange(int w, int start, int end);

		int getWeek() const;
		void setWeek(int w);
		int getBeginSlot() const;
		void setBeginSlot(int newBegin);
		int getEndSlot() const;
		void setEndSlot(int newEnd);

		void output(ostream& outs) const;

		bool isValid() const;

};


#endif // !SLOTRANGE_HPP