/*
 * University.cpp
 *
 *  Created on: Jun 5, 2013
 *      Author: arbel
 */

#include "University.h"

University University::university(100, "");

University& University::GetObj() {
	return university;
}

size_t University::RaisePrice(size_t newPrice) {
	price = newPrice;
	Notify(PRICE);
	return price;
}

void University::CancelLecture(const string& courseName) {
	lastMassage = courseName;
	Notify(LECTURE_CANCELATION);
}

const string& University::GetLastMessage() const {
	return lastMassage;
}

size_t University::GetPrice() const {
	return price;
}

void University::Notify() {
	Subject::Notify();
}

void University::Notify(Notification notification) {
	if (notification == PRICE){
		Notify();
	}
	else{
		for (size_t i = 0; i < m_observers.size(); i++){
			Student* student = dynamic_cast<Student*>(m_observers[i]);
			if (!student) continue;
			if (student->GetFaculty() == "ESF")
				(m_observers[i])->Update(this);
		}
	}
}

University::University(size_t iPrice, const string& firstMessage) :
		price(iPrice),
		lastMassage(firstMessage) {}

