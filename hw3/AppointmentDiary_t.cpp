#include "AppointmentDiary_t.h"

ostream& operator << (ostream& os, const AppointmentDiary_t& diary) {

	return os; // add the printing stuff <<
}

inline bool AppointmentDiary_t::Add(const Appointment_t& appointment) {
	Schedule_t::iterator it = schedule.find(appointment.getTime());
	if (it != schedule.end()) {
		return false;
	}
	pair<Schedule_t::iterator, bool> result =
			schedule.insert(pair<AppointmentTime_t, Appointment_t>
								(appointment.getTime(), appointment));
	return result.second;
}

AppointmentDiary_t::AppointmentDiary_t() { }

AppointmentDiary_t::~AppointmentDiary_t() { }

inline bool AppointmentDiary_t::Remove(const Appointment_t& appointment) {
	Schedule_t::iterator it = schedule.find(appointment.getTime());
	if (it == schedule.end() || it->second != appointment) {
		return false;
	}
	schedule.erase(it);
	return true;
}

inline const Appointment_t* AppointmentDiary_t::Get(
		const AppointmentTime_t& time) const {
	Schedule_t::const_iterator it = schedule.find(time);
	if (it == schedule.end()) {
		return 0;
	}
	return &(it->second);
}

inline bool AppointmentDiary_t::Reschedule(Appointment_t& appointment,
		AppointmentTime_t& new_time) {
	// Make sure that the appointment is indeed in the schedule
	Schedule_t::iterator it = schedule.find(appointment.getTime());
	if (it == schedule.end() || it->second != appointment) {
		return false;
	}
	const Appointment_t* tmp = Get(new_time);
	if (tmp && *tmp != appointment) {
		return false;
	}

	Remove(appointment);
	appointment.setTime(new_time);
	Add(appointment);
	return true;
}
