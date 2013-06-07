#ifndef UNIVERSITY_H_
#define UNIVERSITY_H_

#include "Subject.h"
#include "Student.h"

class University : public Subject {
public:
	static University& getObj();
	int RaisePrice(int newPrice);
	void CancelLecture(const string& courseName);

private:
	static University university;
	University(int iPrice);
	University(University& uni);
	void operator=(University& rhs);

	size_t price;

};







#endif
