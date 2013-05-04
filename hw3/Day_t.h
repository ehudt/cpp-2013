#ifndef _DAY_T_H
#define _DAY_T_H
#include <map>

using namespace std;
class Appointment_t;
class Appointment_t;

class Day_t{
public:
	Day_t(int day);
	virtual ~Day_t();
	Day_t(const Day_t& other);
	Day_t& operator= (const Day_t& day);

	virtual bool add(const Appointment_t& appointment);
	virtual bool remove(Appointment_t& appointment);
	virtual const Appointment_t& get(AppointmentTime_t& time) const;

private:
	map<AppointmentTime_t, Appointment_t> appointments;
	int day;
};

#endif
