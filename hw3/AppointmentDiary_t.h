#ifndef _APPOITMENTDIARY_T_H
#define _APPOITMENTDIARY_T_H

#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <iomanip>

#include "AppointmentTime_t.h"
#include "Appointment_t.h"

using namespace std;

typedef map<AppointmentTime_t, Appointment_t, less<AppointmentTime_t> > Schedule_t;

class AppointmentDiary_t {
	friend ostream& operator << (ostream& os, const AppointmentDiary_t& diary);

public:
	AppointmentDiary_t();
	virtual ~AppointmentDiary_t();
	virtual bool Add(const Appointment_t& appointment);
	virtual bool Remove(const Appointment_t& appointment);
	// Get an appointment form the diary. returns NULL if no such appointment exists
	virtual const Appointment_t* Get(const AppointmentTime_t& time) const;
	virtual const Appointment_t* Get(int day, int start_hour, int start_minutes) const;
	virtual bool Reschedule(const Appointment_t& appointment, const AppointmentTime_t& new_time);

private:
	AppointmentDiary_t(const AppointmentDiary_t& other); // Can't copy Diary
	AppointmentDiary_t& operator =(const AppointmentDiary_t& rhs); // Can't copy Diary
	Schedule_t schedule;
};


#endif // _APPOINTMENT_T_H
