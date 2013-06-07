#ifndef _STUDENTFACTORY_H
#define _STUDENTFACTORY_H

#include <string>

#include "StudentESF.h"
#include "StudentFOH.h"

using namespace std;

class StudentImpl;
class University;

class StudentFactory {
public:
	static StudentImpl* Create(const string& type, const string& name, University* subj);

private:
	StudentFactory();
	StudentFactory(const StudentFactory& factory);
	StudentFactory& operator=(const StudentFactory& rhs);
	~StudentFactory();
};

#endif
