#include "Appointment_t.h"
#include "AppointmentTime_t.h"
#include <assert.h>
#include <iostream>

using namespace std;

void AppointmentTest() {
	AppointmentTime_t t1(1, 8, 30, 11, 30);
	AppointmentTime_t t2(2, 10, 30, 11, 0);

	string s1("Watch the paint dry");

	Appointment_t a1(t1, s1);
	assert(a1.getTime() == t1);
	assert(a1.getSubject() == s1);
	a1.setTime(t2);
	assert(a1.getTime() == t2);
	Appointment_t a2(a1);
	assert(a1 == a2);
	assert(a2.getTime() == t2);
	a1.setTime(t1);
	assert(a2.getTime() == t2);
	assert(a1.getTime() == t1);
	assert(a1!=a2);
}
