#include "Day_t.h"
#include "Appointment_t.h"
#include <assert.h>
#include <iostream>


using namespace std;

void DayTest() {
	AppointmentTime_t t1(1, 8, 30, 11, 30);
	AppointmentTime_t t2(2, 10, 30, 11, 0);

	string s1("First");
	string s2("Second");

	const Appointment_t a1(t1,s1);
	const Appointment_t a2(t2,s2);

	Day_t day(1);

	assert(day.Add(a1));
	assert(day.Get(a1.getTime()));
	assert(day.Remove(a1));
	assert(!day.Add(a2));
	assert(!day.Get(a2.getTime()));
	assert(!day.Remove(a2));
}
