#ifndef UNIVERSITY_H_
#define UNIVERSITY_H_

#include "Subject.h"
#include "Student.h"

class Student;

enum Notification {
	PRICE,
	LECTURE_CANCELATION
};

class University : public Subject {
public:
	static University& GetObj();
	size_t RaisePrice(size_t newPrice);
	void CancelLecture(const string& courseName);
	const string& GetLastMessage();
	size_t GetPrice();
	void Notify(Notification notification);


private:
	static University university;
	University(size_t iPrice, const string& firstMessage);
	University(University& uni);
	void operator=(University& rhs);
	size_t price;
	string lastMassage;
};


#endif
