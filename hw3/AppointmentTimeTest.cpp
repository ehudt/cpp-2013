#include <assert.h>
#include <iostream>

#include "AppointmentTime_t.h"

using namespace std;

class AppointmentTime_t;

void AppointmentTimeTest() {
	// Test that time fields are interpolated correctly by constructor
	AppointmentTime_t app1(1, 8, 30, 11, 30);
	assert(app1.getDay() == 1);
	assert(app1.getStartHour() == 8);
	assert(app1.getStartMinutes() == 30);
	assert(app1.getEndHour() == 11);
	assert(app1.getEndMinutes() == 30);
	assert(app1.getDuration() == 180);

	AppointmentTime_t app2(1, 10, 30, 30);
	assert(app2.getDay() == 1);
	assert(app2.getStartHour() == 10);
	assert(app2.getStartMinutes() == 30);
	assert(app2.getEndHour() == 11);
	assert(app2.getEndMinutes() == 0);
	assert(app2.getDuration() == 30);

	AppointmentTime_t app3(3, 8, 30, 9, 30);
	AppointmentTime_t app4(3, 8, 30, 30);

	// Test that oeprator < returns true iff 2 meetings are overlapping
	assert(app1 == app2);
	assert(app1 != app3);
	assert(app1 != app4);
	assert(app2 != app3);
	assert(app2 != app4);
	assert(app3 == app4);

	// Test operator <
	AppointmentTime_t app5(3, 9, 0, 9, 50);
	assert(app1 < app3);
	assert(app4 < app5);

	// Test operator =
	app5 = app1;
	assert(app1.getDay() == app5.getDay());
	assert(app1.getDuration() == app5.getDuration());
	assert(app1.getStartHour() == app5.getStartHour());
	assert(app1.getStartMinutes() == app5.getStartMinutes());
	assert(app1.getEndHour() == app5.getEndHour());
	assert(app1.getEndMinutes() == app5.getEndMinutes());
	assert(app1 == app5);
	assert(!(app1 < app5) && !(app5 < app1));

	// Test copy CTOR
	AppointmentTime_t app6(app2);
	assert(app2.getDay() == app6.getDay());
	assert(app2.getDuration() == app6.getDuration());
	assert(app2.getStartHour() == app6.getStartHour());
	assert(app2.getStartMinutes() == app6.getStartMinutes());
	assert(app2.getEndHour() == app6.getEndHour());
	assert(app2.getEndMinutes() == app6.getEndMinutes());
	assert(app2 == app6);
	assert(!(app2 < app6) && !(app6 < app2));

	// Test CTOR
	bool caught = false;
	try { new AppointmentTime_t(0, 4, 50, 5, 0); }
	catch (DiaryError& ex) {
		if (ex == InvalidTime) caught = true;
	}
	assert(caught);

	caught = false;
	try { new AppointmentTime_t(7, 24, 0, 24, 10); }
	catch (DiaryError& ex) {
		if (ex == InvalidTime) caught = true;
	}
	assert(caught);

	caught = false;
	try { new AppointmentTime_t(5, 13, 105, 14, 20); }
	catch (DiaryError& ex) {
		if (ex == InvalidTime) caught = true;
	}
	assert(caught);

	caught = false;
	try { new AppointmentTime_t(3, 17, 30, 26, 30); }
	catch (DiaryError& ex) {
		if (ex == InvalidTime) caught = true;
	}
	assert(caught);

	caught = false;
	try { new AppointmentTime_t(3, 17, 30, 18, 90); }
	catch (DiaryError& ex) {
		if (ex == InvalidTime) caught = true;
	}
	assert(caught);
}
