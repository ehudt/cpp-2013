#ifndef _APPOINTMENT_H
#define _APPOINTMENT_H

class Appointment {

public:


private:
	Day  day;
	Hour startHour;
	Hour endHour;
	char subject[];
	char invited[][];
};
