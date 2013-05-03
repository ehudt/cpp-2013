#include "AppointmentTime_t.h"

const int minute_u = 1;
const int hour_u = minute_u * 60;
const int day_u = hour_u * 24;

AppointmentTime_t::AppointmentTime_t(int day, int hour, int minutes,
		int duration_in_minutes) throw (DiaryError) {
	// Check bounds on input
	if (!(day >= 1 && day <= 7)
			|| !(hour >= 0 && hour <= 23)
			|| !(minutes >= 0 && minutes <= 59)) {
		throw InvalidTime;
	}
	// Calculate the time in minutes passed since beginning of week
	int start_minutes = day * day_u + hour * hour_u + minutes * minute_u;
	// Make sure that the meeting starts and ends on the same day
	if ((start_minutes + duration_in_minutes) / day_u > day) {
		throw MeetingPassesMidnight;
	}
	// Initialize object
	start = start_minutes;
	duration = duration_in_minutes;
}

bool AppointmentTime_t::operator ==(const AppointmentTime_t& rhs) const {
	return !(*this < rhs) && !(rhs < *this);
}

bool AppointmentTime_t::operator !=(const AppointmentTime_t& rhs) const {
	return !(*this == rhs);
}

AppointmentTime_t::AppointmentTime_t(int start, int duration) :
	start(start),
	duration(duration) {}

AppointmentTime_t::~AppointmentTime_t() {}

AppointmentTime_t::AppointmentTime_t(const AppointmentTime_t& other) :
	start(other.start),
	duration(other.duration) {}

AppointmentTime_t& AppointmentTime_t::operator =(const AppointmentTime_t& rhs) {
	if (this != &rhs) {
		this->start = rhs.start;
		this->duration = rhs.duration;
	}
	return *this;
}

bool AppointmentTime_t::operator <(const AppointmentTime_t& rhs) const {
	return start + duration <= rhs.start;
}

int AppointmentTime_t::getDay() const {
	return start / day_u;
}

int AppointmentTime_t::getHour() const {
	return (start % day_u) / hour_u;
}

int AppointmentTime_t::getMinutes() const {
	return start % hour_u;
}

int AppointmentTime_t::getDuration() const {
	return duration;
}


