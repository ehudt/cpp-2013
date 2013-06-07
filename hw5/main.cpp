#include <iostream>
#include <vector>
#include <limits>

#include "University.h"
#include "Student.h"

// Macro for token input
#define GetToken(c) do {\
		cin >> c;\
		if (!cin.good()) {\
			cin.clear();\
			cin.ignore(numeric_limits<streamsize>::max(), '\n');\
			break;}\
	} while(0)

using namespace std;

int main() {
	University& university = University::GetObj();
	vector<Student*> students;
	const string faculty[] = {"FOH", "ESF", ""};

	bool cont = true;
	unsigned int c = (unsigned)-1;
	while (cont) {
		cout    << "    Welcome to Greendale Community college!" << endl
				<< "    What would you like to do?" << endl
				<< "    1: Add a student to FOH" << endl
				<< "    2: Add a student to ESF" << endl
				<< "    3: Change tuition price" << endl
				<< "    4: Notify of a canceled class in ESF" << endl
				<< "    other: quit" << endl
				<< "Enter your choice: ";

		GetToken(c);

		string name;
		Student* student;
		size_t new_price;
		string cancel_message;

		switch (c) {
			case 1:
			case 2:
				cout << "Enter student name: ";
				GetToken(name);
				student = new Student(faculty[c - 1], name, &university);
				students.push_back(student);
				break;
			case 3:
				cout << "Enter new tuition price: ";
				GetToken(new_price);
				university.RaisePrice(new_price);
				break;
			case 4:
				cout << "Enter class cancellation message: ";
				cin.get();
				getline(cin, cancel_message);
				university.CancelLecture(cancel_message);
				break;
			default:
				cont = false;
				break;
		}

	}
	// Free memory
	for (vector<Student*>::iterator it = students.begin(); it != students.end(); ++it) {
		delete *it;
	}
	return 0;
}
