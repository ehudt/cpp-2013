#ifndef _DAY_T_H
#define _DAY_T_H

#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <iomanip>

#include "AppointmentTime_t.h"
#include "Appointment_t.h"
#include "AppointmentDiary_t.h"

class AppointmentDiary_t;

using namespace std;

typedef map<AppointmentTime_t, Appointment_t, less<AppointmentTime_t> > Schedule_t;

class Day_t {
	friend ostream& operator << (ostream& os, const AppointmentDiary_t& diary);

public:
	Day_t(int day);
	virtual ~Day_t();
	//Day_t(const Day_t& other);
	//Day_t& operator= (const Day_t& day);

	virtual bool Add(const Appointment_t& appointment);
	virtual bool Remove(const Appointment_t& appointment);
	// Get an appointment form the diary. returns NULL if no such appointment exists
	virtual const Appointment_t* Get(const AppointmentTime_t& time) const;
	virtual const Appointment_t* Get(int start_hour, int start_minutes) const;

private:
	int day;
	Schedule_t schedule;
};

#endif
