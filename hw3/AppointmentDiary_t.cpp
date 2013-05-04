#include "AppointmentDiary_t.h"
#include <sstream>

inline bool AppointmentDiary_t::Add(const Appointment_t& appointment) {
	int day = appointment.getTime().getDay() - 1;
	return days[day]->Add(appointment);
}

AppointmentDiary_t::AppointmentDiary_t() {
	for (int i = 1; i <= 7; ++i) {
		days[i-1] = new Day_t(i);
	}
}

AppointmentDiary_t::~AppointmentDiary_t() {
	for (int i = 1; i <= 7; ++i) {
		delete days[i-1];
	}
}

inline bool AppointmentDiary_t::Remove(const Appointment_t& appointment) {
	int day = appointment.getTime().getDay() - 1;
	return days[day]->Remove(appointment);
}

inline const Appointment_t* AppointmentDiary_t::Get(
		const AppointmentTime_t& time) const {
	int day = time.getDay() - 1;
	return days[day]->Get(time);
}

const Appointment_t* AppointmentDiary_t::Get(int day, int start_hour,
		int start_minutes) const {
	return days[day-1]->Get(start_hour, start_minutes);
}

inline bool AppointmentDiary_t::Reschedule(const Appointment_t& appointment,
		const AppointmentTime_t& new_time) {
	// Make sure that the appointment is indeed in the schedule
	//Schedule_t::iterator it = schedule.find(appointment.getTime());
	Appointment_t* find_app = (Appointment_t *) Get(appointment.getTime());
	if (!find_app || *find_app != appointment) {
		return false;
	}
	Appointment_t& reschedule_appointment = *find_app;
	const Appointment_t* tmp = Get(new_time);
	if (tmp && *tmp != appointment) {
		return false;
	}
	Remove(appointment);
	reschedule_appointment.setTime(new_time);
	Add(reschedule_appointment);
	return true;
}


const int screen_width = 142;
const int hour_fill = 6;
const int day_fill = 18;
const int column_width = 18;

static string MakeHeader() {
	ostringstream header;
	string week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	header << endl << setfill('_') << setw(screen_width) << " " << endl;
	header << "|" << setfill(' ') << left << setw(hour_fill) << "Hour" << "|" << right;
	for (int i = 0; i < 7; i++){
		header << left << setw(day_fill) << week[i] << "|" << right;
	}
	header << endl;
	header << setfill('-') << setw(screen_width) << " " << endl;
	return header.str();
}

ostream& operator << (ostream& os, const AppointmentDiary_t& diary) {
/*
	// Output diary header
	string header = MakeHeader();
	os << header;

	// Calculate how many lines each day needs
	int hour_lines[24] = {0};
	int current_day = 1;
	//int current_lines = 0;
	int current_day_lines[24] = {0};
	for (Schedule_t::const_iterator it = diary.schedule.begin();
			it != diary.schedule.end(); ++it) {
		const Appointment_t& appointment = it->second;
		const AppointmentTime_t time = appointment.getTime();
		//const string& subject = appointment.getSubject();

		ostringstream appointment_sstream;
		appointment_sstream << appointment;
		const string& app_str = appointment_sstream.str();

		// If the day changed, flush the previous day's line count
		if(time.getDay() > current_day) {
			for (int i = 0; i < 24; ++i) {
				hour_lines[i] = max(current_day_lines[i], hour_lines[i]);
				current_day_lines[i] = 0;
			}
			current_day = time.getDay();
		}

		int start_hour = time.getStartHour();
		int hour_span = time.getEndHour() - time.getStartHour()
				+ (time.getEndMinutes() > 0 ? 1 : 0);
		int lines_for_subject = 1 + app_str.length() / column_width;
		int lines_per_hour = lines_for_subject / hour_span;
		for (int i = start_hour; i < start_hour + hour_span; ++i ) {
			current_day_lines[i] += lines_per_hour;
		}
		//hour_lines[appointment.getTime().getStartHour()] += appointment.getSubject().length() / column_width;
	}
	// Flush last day
	for (int i = 0; i < 24; ++i) {
		hour_lines[i] = max(current_day_lines[i], hour_lines[i]);
		current_day_lines[i] = 0;
	}

	ostringstream hours;
	for (int i = 0; i < 24; ++i) {
		//if (hour_lines[i] == 0) continue;
		int lines = max(2, hour_lines[i]);
		ostringstream int_to_str;
		int_to_str << i;
		string hour(int_to_str.str());
		string min(":00");
		hours << setfill(' ') << setw(hour_fill) << hour+min << endl;
		lines--;
		while(lines > 1) {
			hours << endl;
			lines--;
		}
		hours << setfill('-') << setw(hour_fill) << "" << endl;
	}
	string hours_str = hours.str();
	os << hours_str;
	//ostringstream day_stream[7];

	// TODO this is not good yet
//	for (Schedule_t::const_iterator it = diary.schedule.begin();
//			it != diary.schedule.end(); ++it) {
//		const Appointment_t& appointment = it->second;
//		const AppointmentTime_t time = appointment.getTime();
//		int day = time.getDay() - 1;
//
//		ostringstream appointment_sstream;
//		appointment_sstream << appointment;
//		const string& app_str = appointment_sstream.str();
//
//		int chars_left = column_width;
//		for (string::const_iterator c = app_str.start();
//				c != app_str.end(); ++c) {
//			day_stream
//		}
//
//
//	}



	//string			day_str[7];
*/
	return os;
}
