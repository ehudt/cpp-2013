/*
 * University.cpp
 *
 *  Created on: Jun 5, 2013
 *      Author: arbel
 */

#include "University.h"


University& University::getObj() {
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

const string& University::getLastMassage() {
	return lastMassage;
}

size_t University::getPrice() {
	return price;
}

void University::Notify(Notification notification) {
	if (notification == PRICE){
		for (size_t i = 0; i < m_observers.size(); i++)
			(m_observers[i])->Update(this);
	}
	else{
		for (size_t i = 0; i < m_observers.size(); i++){
			Student* student = dynamic_cast<Student*>(m_observers[i]);
			if (student->GetFaculty() == "ESF")
				(m_observers[i])->Update(this);
		}
	}
}

University::University(size_t iPrice, string& firstMessage) :
		price(iPrice),
		lastMassage(firstMessage) {}

