#ifndef _DAY_T_H
#define _DAY_T_H
#include <map>
#include "Appointment_t.h"

using namespace std;
class Appointment_t;

class Day_t{
public:
	Day_t(int day);
	virtual ~Day_t();

	bool addAppointment(const Appointment_t& appointment);
	bool removeAppointment(Appointment_t& appointment);
	const Appointment_t& getAppointment(AppointmentTime_t& time) const;

private:
	Day_t(const Day_t& other);
	Day_t& operator= (const Day_t& day);
	map<AppointmentTime_t, Appointment_t> appointments;
	int day;
};

#endif
