#ifndef _STUDENTFACTORY_H
#define _STUDENTFACTORY_H

#include <string>

using namespace std;

class Student;

class StudentFactory {
public:
	static Student* Create(const string& type, const string& name);

public:
	StudentFactory();
	StudentFactory(const StudentFactory& factory);
	StudentFactory& operator=(const StudentFactory& rhs);
};

#endif
