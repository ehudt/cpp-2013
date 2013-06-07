#ifndef UNIVERSITY_H_
#define UNIVERSITY_H_

#include "Subject.h"
#include "Student.h"

enum Notification {
	PRICE,
	LECTURE_CANCELATION
};

class University : public Subject {
public:
	static University& getObj();
	size_t RaisePrice(size_t newPrice);
	void CancelLecture(const string& courseName);
	const string& getLastMassage();
	size_t getPrice();
	void Notify(Notification notification);


private:
	static University university;
	University(size_t iPrice, string& firstMessage);
	University(University& uni);
	void operator=(University& rhs);
	string& lastMassage;
	size_t price;

};


#endif
