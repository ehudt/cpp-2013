#ifndef _STUDENTFACTORY_H
#define _STUDENTFACTORY_H

#include <string>

using namespace std;

class StudentImpl;

class StudentFactory {
public:
	static StudentImpl* Create(const string& type, const string& name);

private:
	StudentFactory();
	StudentFactory(const StudentFactory& factory);
	StudentFactory& operator=(const StudentFactory& rhs);
	~StudentFactory();
};

#endif
