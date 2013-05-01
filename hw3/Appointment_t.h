#ifndef _APPOINTMENT_T_H
#define _APPOINTMENT_T_H
#include "Hour_t.h"
class Appointment_t {

public:
	Appointment_t();
	Appointment_t(Hour_t startHour, Hour_t endHour, char* subject);
	~Appointment_t();

	const Appointment_t& operator= (const Appointment_t& appointment);
	const Appointment_t& operator== (const Appointment_t& appointment) const;

	const  Hour_t getStartHour() const;
	const  Hour_t getEndHour() const;
	const char* getSubject() const;
	const char** invited() const;

private:
	Hour_t  startHour;
	Hour_t  endHour;
	char subject[];
};

#endif
