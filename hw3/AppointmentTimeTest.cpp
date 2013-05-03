#include "AppointmentTime_t.h"
#include <assert.h>
#include <iostream>

using namespace std;

void AppointmentTimeTest() {
	// Test that time fields are interpolated correctly by constructor
	AppointmentTime_t app1(1, 8, 30, 180);
	assert(app1.getDay() == 1);
	assert(app1.getHour() == 8);
	assert(app1.getMinutes() == 30);
	assert(app1.getDuration() == 180);

	AppointmentTime_t app2(1, 10, 30, 30);
	assert(app2.getDay() == 1);
	assert(app2.getHour() == 10);
	assert(app2.getMinutes() == 30);
	assert(app2.getDuration() == 30);

	AppointmentTime_t app3(3, 8, 30, 60);
	AppointmentTime_t app4(3, 8, 30, 30);

	// Test that oeprator < returns true iff 2 meetings are overlapping
	assert(app1 == app2);
	assert(app1 != app3);
	assert(app1 != app4);
	assert(app2 != app3);
	assert(app2 != app4);
	assert(app3 == app4);

	// Test operator <
	AppointmentTime_t app5(3, 9, 0, 50);
	assert(app1 < app3);
	assert(app4 < app5);

	// Test operator =
	app5 = app1;
	assert(app1.getDay() == app5.getDay());
	assert(app1.getDuration() == app5.getDuration());
	assert(app1.getHour() == app5.getHour());
	assert(app1.getMinutes() == app5.getMinutes());
	assert(app1 == app5);
	assert(!(app1 < app5) && !(app5 < app1));

	// Test copy CTOR
	AppointmentTime_t app6(app2);
	assert(app2.getDay() == app6.getDay());
	assert(app2.getDuration() == app6.getDuration());
	assert(app2.getHour() == app6.getHour());
	assert(app2.getMinutes() == app6.getMinutes());
	assert(app2 == app6);
	assert(!(app2 < app6) && !(app6 < app2));

	// Test CTOR
	AppointmentTime_t* app = 0;
	bool caught = false;
	try { app = new AppointmentTime_t(0, 4, 50, 10); }
	catch (DiaryError& ex) {
		if (ex == InvalidTime) caught = true;
	}
	assert(caught);

	caught = false;
	try { app = new AppointmentTime_t(7, 24, 0, 10); }
	catch (DiaryError& ex) {
		if (ex == InvalidTime) caught = true;
	}
	assert(caught);

	caught = false;
	try { app = new AppointmentTime_t(5, 13, 105, 240); }
	catch (DiaryError& ex) {
		if (ex == InvalidTime) caught = true;
	}
	assert(caught);

	caught = false;
	try { app = new AppointmentTime_t(3, 17, 30, 600); }
	catch (DiaryError& ex) { caught = true; }
	assert(caught);
	cout << "AppointmentTimeTest() finished successfully!" << endl;
}
