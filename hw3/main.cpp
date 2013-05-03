#include "AppointmentDiary_t.h"
#include "AppointmentTime_t.h"
#include "Appointment_t.h"

#include <iostream>
using namespace std;

void AppointmentTimeTest();
void AppointmentTest();
void AppointmentDiaryTest();

int main(void) {
	// Run all tests in this block
	AppointmentTimeTest();
	cout << "AppointmentTimeTest() finished successfully!" << endl;
	AppointmentTest();
	cout << "AppointmentTest() finished successfully!" << endl;
	AppointmentDiaryTest();
	cout << "AppointmentDiaryTest() finished successfully!" << endl;
	cout << "All tests passed!" << endl;



	// Demo program starts here




	return 0;
}
