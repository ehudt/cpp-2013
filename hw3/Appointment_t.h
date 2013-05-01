#ifndef _APPOINTMENT_T_H
#define _APPOINTMENT_T_H
#include "AppointmentTime_t.h"
class Appointment_t {

public:
	Appointment_t();
	Appointment_t(AppointmentTime_t time, char* subject);
	~Appointment_t();

	const Appointment_t& operator= (const Appointment_t& appointment);
	const Appointment_t& operator== (const Appointment_t& appointment) const;

	const  AppointmentTime_t getTime() const;
	const char* getSubject() const;

private:
	AppointmentTime_t appointmentTime;
	char subject[];
};

#endif
