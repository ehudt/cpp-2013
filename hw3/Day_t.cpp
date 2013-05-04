#include "Day_t.h";

Day_t::Day_t(int day) :
	day(day) {}

Day_t::~Day_t() {}

bool Day_t::Add(const Appointment_t& appointment) {
	Schedule_t::iterator it = schedule.find(appointment.getTime());
	if (it != schedule.end()) {
		return false;
	}
	pair<Schedule_t::iterator, bool> result =
			schedule.insert(pair<AppointmentTime_t, Appointment_t>
				(appointment.getTime(), appointment));
	return result.second;
}

bool Day_t::Remove(const Appointment_t& appointment) {
	Schedule_t::iterator it = schedule.find(appointment.getTime());
	if (it == schedule.end() || it->second != appointment) {
		return false;
	}
	schedule.erase(it);
	return true;
}

const Appointment_t* Day_t::Get(const AppointmentTime_t& time) const {
	Schedule_t::const_iterator it = schedule.find(time);
	if (it == schedule.end()) {
		return 0;
	}
	return &(it->second);
}

const Appointment_t* Day_t::Get(int start_hour, int start_minutes) const {
	try {
		AppointmentTime_t tmp_time(day, start_hour, start_minutes, 1);
		const Appointment_t* app_p = Get(tmp_time);
		if (!app_p) return 0;
		const AppointmentTime_t& app_time = app_p->getTime();
		if (app_time.getStartHour() != start_hour
				|| app_time.getStartMinutes() != start_minutes) {
			return 0;
		}
		return app_p;
	} catch (DiaryError& ex) {
		return 0;
	}
}
