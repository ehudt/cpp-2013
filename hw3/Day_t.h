#ifndef _DAY_T_H
#define _DAY_T_H
#include <map>
#include "Appointment_t.h"

using namespace std;


class Day_t{
public:
	Day_t();
	~Day_t();

	const Day_t& operator= (const Day_t& day);

private:
	map<Hour_t, Appointment_t> appointments;
	int day;

};

#endif
