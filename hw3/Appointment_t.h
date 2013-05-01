#ifndef _APPOINTMENT_T_H
#define _APPOINTMENT_T_H

class Appointment_t {

public:
	Appointment_t();
	Appointment_t(AppointmentTime_t appTime, char* subject);
	~Appointment_t();

	const Appointment_t& operator= (const Appointment_t& appointment);
	const Appointment_t& operator== (const Appointment_t& appointment) const;

	const  AppointmentTime_t gettime() const;
	const char* getSubject() const;
	const char** invited() const;

private:
	AppointmentTime_t  time;
	char subject[];
};

#endif
