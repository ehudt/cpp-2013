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
	// Output diary header
	string header = MakeHeader();
	os << header;

	// Calculate how many lines each day needs
	int hour_lines[24] = {0};
	//int current_lines = 0;
	int current_day_lines[24] = {0};

	for (int current_day = 1; current_day <= 7; ++current_day) {
		Day_t& day = *diary.days[current_day-1];

		for (Schedule_t::const_iterator it = day.schedule.begin();
					it != day.schedule.end(); ++it) {
			const Appointment_t& appointment = it->second;
			const AppointmentTime_t time = appointment.getTime();
			//const string& subject = appointment.getSubject();

			ostringstream appointment_sstream;
			appointment_sstream << appointment;
			const string& app_str = appointment_sstream.str();

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
		// Flush the day's results into the main array
		for (int i = 0; i < 24; ++i) {
			hour_lines[i] = max(current_day_lines[i], hour_lines[i]);
			current_day_lines[i] = 0;
		}
	}

	ostringstream hours;
	for (int i = 0; i < 24; ++i) {
		if (hour_lines[i] == 0) continue;
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

	ostringstream day_stream[7];

	for (int current_day = 1; current_day <= 7; ++current_day) {
		Day_t& day = *diary.days[current_day-1];
		int prev_hour = -1;
		for (Schedule_t::const_iterator it = day.schedule.begin();
				it != day.schedule.end(); ++it) {
			const Appointment_t& appointment = it->second;
			const AppointmentTime_t time = appointment.getTime();
			int start_hour = time.getStartHour();
			int hour_span = time.getEndHour() - time.getStartHour()
										+ (time.getEndMinutes() > 0 ? 1 : 0);
			ostringstream& stream = day_stream[current_day-1];
			for (int i = prev_hour + 1; i < start_hour; ++i) {
				for (int j = 0; j < hour_lines[i]; ++j) {
					stream << endl;
				}
			}
			int needed_lines = 0;
			for (int i = start_hour; i < start_hour + hour_span; ++i) {
				needed_lines += hour_lines[i];
			}
			ostringstream appointment_sstream;
			appointment_sstream << appointment;
			const string& app_str = appointment_sstream.str();

			int char_count = 0;

			for (string::const_iterator c = app_str.begin();
					c != app_str.end(); ++c) {
				stream << *c;
				char_count++;
				if (char_count % column_width == 0) {
					stream << endl;
					needed_lines--;
				}
			}
			stream << endl;
			needed_lines--;
			stream << setfill('-') << setw(column_width) << "" << endl;
			needed_lines--;
			if (hour_span > 1) {
				for (int i = 0; i < needed_lines; ++i) {
					stream << endl;
				}
				needed_lines = 0;
			}
		}
	}

	string column_str[8];
	string::const_iterator str_it[8];
	column_str[0] = hours_str;
	str_it[0] = column_str[0].begin();
	for (int i = 1; i <= 7; ++i) {
		column_str[i] = (day_stream[i-1].str());
		str_it[i] = column_str[i].begin();
	}

	os << left;
	bool ended = false;
	while(!ended) {
		for (int i = 0; i <= 7; ++i) {
			if (str_it[i] == column_str[i].end()) {
				ended = true;
				os << setfill(' ') << setw(i ? column_width : hour_fill) << "" << '|';
				continue;
			}
			ended = false;
			ostringstream tmp;
			while (*str_it[i] != '\n' && str_it[i] != column_str[i].end()) {
				tmp << *str_it[i];
				++(str_it[i]);
			}
			++(str_it[i]);
			os << setfill(' ') << setw(i ? column_width : hour_fill) << tmp.str() << '|';

		}
		os << endl;
	}
	return os;
}
