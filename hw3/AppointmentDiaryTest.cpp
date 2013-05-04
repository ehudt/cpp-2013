#include <assert.h>

#include "AppointmentDiary_t.h"

class AppointmentDiary_t;
class Appointment_t;
class AppointmentTime_t;

void AppointmentDiaryTest() {
	AppointmentDiary_t diary;

	// Add an appointment and make sure that it's in the schedule
	AppointmentTime_t time1(7, 8, 30, 10, 0);
	string subject1("Coffee with mom");
	Appointment_t app1(time1, subject1);
	assert(diary.Add(app1));
	assert(*diary.Get(app1.getTime()) == app1);

	// Add a conflicting appointment
	AppointmentTime_t time2(7, 9, 30, 11, 30);
	string subject2("Brunch with Arbel");
	Appointment_t app2(time2, subject2);
	assert(!diary.Add(app2));

	// Reschedule appointment 1 to make room for appointment 2
	AppointmentTime_t time3(7, 8, 0, 9, 30);
	diary.Reschedule(app1, time3);
	const Appointment_t* tmp = diary.Get(7, 8, 0);
	assert(tmp);
	assert(*tmp == app1);
	const AppointmentTime_t& tmp_time = tmp->getTime();
	assert(tmp_time.getStartHour() == 8
			&& tmp_time.getStartMinutes() == 0
			&& tmp_time.getEndHour() == 9
			&& tmp_time.getEndMinutes() == 30);

	// Add appointment 2
	assert(diary.Add(app2));
}
