#ifndef _APPOINTMENTTIME_T_H
#define _APPOINTMENTTIME_T_H

#include "DiaryError.h"

class AppointmentTime_t{
public:
	AppointmentTime_t(int start_day, int start_hour, int start_minutes,
			int end_hour, int end_minutes) throw (DiaryError);
	virtual ~AppointmentTime_t();
	AppointmentTime_t(const AppointmentTime_t& other);
	AppointmentTime_t& operator =(const AppointmentTime_t& rhs);
	bool operator < (const AppointmentTime_t &rhs) const;
	bool operator == (const AppointmentTime_t &rhs) const;
	bool operator != (const AppointmentTime_t &rhs) const;

	virtual int getDay() const;
	virtual int getStartHour() const;
	virtual int getStartMinutes() const;
	virtual int getEndHour() const;
	virtual int getEndMinutes() const;
	virtual int getDuration() const; // In minutes.

private:
	// time representation
	int start;		// in minutes since Sunday at 00:00
	int end;	// in minutes
};

#endif //_APPOINTMENTTIME_T_H
