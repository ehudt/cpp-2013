#ifndef _APPOITMENTDIARY_T_H
#define _APPOITMENTDIARY_T_H

#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

typedef map<AppointmentTime_t, Appointment_t, less<AppointmentTime_t>> Schedule_t;

class AppointmentDiary_t {
	friend ostream& operator << (ostream& os, const AppointmentDiary_t& diary);

public:
	// AppontmentDiary_t();
	virtual ~AppointmentDiary_t();
	bool Add(const Appointment_t& appointment);
	bool Remove(const Appointment_t& appointment);
	Appointment_t& Get(const AppointmentTime_t& time) const;
	bool Reschedule(Appointment_t& appointment, AppointmentTime_t& new_time);

private:
	AppointmentDiary_t(const AppointmentDiary_t& other); // Can't copy Diary
	AppointmentDiary_t& operator =(const AppointmentDiary_t& rhs); // Can't copy Diary
	Schedule_t schedule;
};


#endif // _APPOINTMENT_T_H
