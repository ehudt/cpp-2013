#ifndef _APPOINTMENT_T_H
#define _APPOINTMENT_T_H
#include "AppointmentTime_t.h"
#include <string>

using namespace std;

class Appointment_t {

public:
	Appointment_t(AppointmentTime_t& time, string& subject);
	Appointment_t(const Appointment_t& other);
	virtual ~Appointment_t();

	Appointment_t& operator= (const Appointment_t& appointment);
	bool operator== (const Appointment_t& appointment) const;
	bool operator!= (const Appointment_t& appointment) const;
	const AppointmentTime_t& getTime() const;
	const string& getSubject() const;
	void setTime(const AppointmentTime_t& newTime);

private:
	AppointmentTime_t appointmentTime;
	string subject;
};

#endif
