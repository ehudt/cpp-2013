#include "AppointmentDiary_t.h"

ostream& operator << (ostream& os, const AppointmentDiary_t& diary) {

	return os; // add the printing stuff <<
}

inline bool AppointmentDiary_t::Add(const Appointment_t& appointment) {
	Schedule_t::iterator it = schedule.find(appointment.getTime());
	if (it == schedule.end()) {
		return false;
	}
	pair<Schedule_t::iterator, bool> result =
			schedule.insert(pair<AppointmentTime_t, Appointment_t>
								(appointment.getTime(), appointment));
}

inline bool AppointmentDiary_t::Remove(const Appointment_t& appointment) {
}

inline Appointment_t& AppointmentDiary_t::Get(
		const AppointmentTime_t& time) const {
}

inline bool AppointmentDiary_t::Reschedule(Appointment_t& appointment,
		AppointmentTime_t& new_time) {
}
