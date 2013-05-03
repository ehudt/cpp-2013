#include "DiaryError.h"

class AppointmentTime_t{
public:
	AppointmentTime_t(int day, int hour, int minutes,
			int duration_in_minutes) throw (DiaryError);
	virtual ~AppointmentTime_t();
	AppointmentTime_t(const AppointmentTime_t& other);
	AppointmentTime_t& operator =(const AppointmentTime_t& rhs);
	bool operator < (const AppointmentTime_t &rhs) const;
	bool operator == (const AppointmentTime_t &rhs) const;
	bool operator != (const AppointmentTime_t &rhs) const;

	int getDay() const;
	int getHour() const;
	int getMinutes() const;
	int getDuration() const;

private:
	AppointmentTime_t(int start, int duration);
	// time representation
	int start;		// in minutes since Sunday at 00:00
	int duration;	// in minutes
};
