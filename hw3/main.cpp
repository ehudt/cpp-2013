#include "AppointmentDiary_t.h"
#include "AppointmentTime_t.h"
#include "Appointment_t.h"
#include <iomanip>
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <limits>

void AppointmentDiaryTest();
void DayTest();
void AppointmentTimeTest();
void AppointmentTest();

int main(void) {

	// Run all tests in this block
	AppointmentTimeTest();
	cout << "AppointmentTimeTest() finished successfully!" << endl;
	AppointmentTest();
	cout << "AppointmentTest() finished successfully!" << endl;
	AppointmentDiaryTest();
	cout << "AppointmentDiaryTest() finished successfully!" << endl;
	DayTest();
	cout << "DayTest() finished successfully!" << endl;
	cout << "All tests passed!" << endl;

	bool cont	= true;			// trigger to stop loop
	unsigned int c = (unsigned)-1;

	AppointmentDiary_t appdiar;

	cout << "Welcome to your Appointment Diary:" << endl;

	while (cont) {
		cout 	<< "	What would you like to do?" << endl
				<< "	0: insert" 				<< endl
				<< "	1: find" 				<< endl
				<< "	2: remove" 				<< endl
				<< "	3: reschedule"			<< endl
				<< "	4: print diary"			<< endl
				<< "	other: quit"			<< endl
				<< "Enter your choice : ";

		cin >> c;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}

		int day, start_hour, end_hour, start_minutes, end_minutes;
		string subject;
		bool success;
		switch (c) {
		case 0:{
			cout << "Enter day for new appointment (1-7): " << endl;
			cin >> day;

			cout<< "Enter start hour(0-23) and minutes (0-59): " << endl;
			cin >> start_hour >> start_minutes;

			cout<< "Enter end hour(0-23) and minutes (0-59): " << endl;
			cin >> end_hour >> end_minutes;

			cout << "Enter subject for appointment: " << endl;
			cin >> subject;

			if (!cin.good()) {
				cout << "Invalid input" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			AppointmentTime_t time(day, start_hour, start_minutes, end_hour, end_minutes);
			Appointment_t appointment(time, subject);
			success = appdiar.Add(appointment);

			cout << "Adding the appointment " << (success ? "succeeded." : "failed.") << endl << endl;
			break;
		}

		case 1: {
			cout << "Enter day, start hour(0-23) and minutes(0-59) of the appointment to find: ";
			cin >> day >> start_hour >> start_minutes;
			if (!cin.good()) {
				cout << "Invalid input" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}

			const Appointment_t* t = appdiar.Get(day, start_hour, start_minutes);
			cout << "Finding the appointment " << (t ? "succeeded." : "failed. No appointment at this time.") << endl << endl;
			break;
		}

		case 2: {
			cout << "Enter day, start hour(0-23) and minutes(0-59) of the appointment to remove: ";
			cin >> day >> start_hour >> start_minutes;
			if (!cin.good()) {
				cout << "Invalid input" << endl << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}

			const Appointment_t *a = appdiar.Get(day, start_hour, start_minutes);
			if (!a){
				success = false;
			}
			else{
				success = appdiar.Remove(*a);
			}
			cout << "Appointment removal " << (success ? "succeeded." : "failed.") << endl << endl;
			break;
		}

		case 3: {
			cout << "Enter day, start hour and minutes for appointment to reschedule: " << endl;
			cin >> day >> start_hour >> start_minutes;
			if (!cin.good()) {
				cout << "Invalid input" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}

			const Appointment_t* a = appdiar.Get(day, start_hour, start_minutes);

			cout << "Enter day, start hour and minutes for the appointment new time: " << endl;
						cin >> day >> start_hour >> start_minutes;
						if (!cin.good()) {
							cout << "Invalid input" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							break;
						}
			const AppointmentTime_t newTime(day, start_hour, start_minutes, a->getTime().getDuration());
			success = appdiar.Reschedule(*a, newTime);

			cout << "Rescheduling " << (success ? "succeeded." : "failed.") << endl << endl;
			break;
		}

		case 4:
			cout << appdiar;
			break;

		default:
			cont = false;
			break;
		}
	}

	cout << "Bye." << endl;
	return 0;
}

