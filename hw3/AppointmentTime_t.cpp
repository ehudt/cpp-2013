#include "AppointmentTime_t.h"

const int minute_u = 1;
const int hour_u = minute_u * 60;
const int day_u = hour_u * 24;

static int getTimeInMinutes(int day, int hour, int minutes) {
	if (!(day >= 1 && day <= 7)
			|| !(hour >= 0 && hour <= 23)
			|| !(minutes >= 0 && minutes <= 59)) {
		return -1;
	}
	return (day - 1) * day_u + hour * hour_u + minutes * minute_u;
}

AppointmentTime_t::AppointmentTime_t(int day, int start_hour,
		int start_minutes, int end_hour, int end_minutes) throw (DiaryError) {
	// Validate start time
	int start_time = getTimeInMinutes(day, start_hour, start_minutes);
	if (start_time < 0) throw InvalidTime;

	// Validate end time
	int end_time = getTimeInMinutes(day, end_hour, end_minutes);
	if (end_time < 0) throw InvalidTime;

	// Make sure that the meeting has a positive duration (0 min. appointment not allowed)
	if (end_time <= start_time) throw InvalidTime;

	// Initialize object
	start = start_time;
	end = end_time;
}

bool AppointmentTime_t::operator <(const AppointmentTime_t& rhs) const {
	return this->end <= rhs.start;
}

bool AppointmentTime_t::operator ==(const AppointmentTime_t& rhs) const {
	return !(*this < rhs) && !(rhs < *this);
}

bool AppointmentTime_t::operator !=(const AppointmentTime_t& rhs) const {
	return !(*this == rhs);
}

AppointmentTime_t::~AppointmentTime_t() {}

AppointmentTime_t::AppointmentTime_t(const AppointmentTime_t& other) :
	start(other.start),
	end(other.end) {}

AppointmentTime_t& AppointmentTime_t::operator =(const AppointmentTime_t& rhs) {
	if (this != &rhs) {
		this->start = rhs.start;
		this->end = rhs.end;
	}
	return *this;
}

int AppointmentTime_t::getDay() const {
	return 1 + start / day_u;
}

int AppointmentTime_t::getStartHour() const {
	return (start % day_u) / hour_u;
}

int AppointmentTime_t::getStartMinutes() const {
	return start % hour_u;
}

int AppointmentTime_t::getEndHour() const {
	return (end % day_u) / hour_u;
}

int AppointmentTime_t::getEndMinutes() const {
	return end % hour_u;
}

AppointmentTime_t::AppointmentTime_t(int day, int start_hour, int start_minutes,
		int duration_in_minutes) throw (DiaryError) {
	int start_time = getTimeInMinutes;
	if (start_time < 0) throw InvalidTime;
	int end_time = start_time + duration_in_minutes;
	if (day < 1 + end_time / day_u) throw TwoDayMeeting;

	start = start_time;
	end = end_time;
}

int AppointmentTime_t::getDuration() const {
	return end - start;
}

//const char* day[] = { "",
//		"Sun ",
//		"Mon ",
//		"Tue ",
//		"Wed ",
//		"Thu ",
//		"Fri ",
//		"Sat ",
//};

ostream& operator << (ostream& os, const AppointmentTime_t& time) {
	return os //<< day[time.getDay()]
	            << time.getStartHour() << ":"
	            << (time.getStartMinutes() < 10 ? "0" : "")
	            << time.getStartMinutes() << "-"
	            << time.getEndHour() << ":"
	            << (time.getEndMinutes() < 10 ? "0" : "")
	            << time.getEndMinutes();
}
