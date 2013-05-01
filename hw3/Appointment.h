#ifndef _APPOINTMENT_H
#define _APPOINTMENT_H

class Appointment {

public:
	Appointment();
	Appointment(AppointmentTime_t appTime, char* subject, char** invited);
	~Appointment();

	const Appointment& operator= (const Appointment& appointment);
	const Appointment& operator== (const Appointment& appointment) const;

	const  AppointmentTime_t gettime() const;
	const char* getSubject() const;
	const char** invited() const;

private:
	AppointmentTime_t  time;
	char subject[];
	char invited[][];
};

#endif
