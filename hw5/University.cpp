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

int University::RaisePrice(int newPrice) {
	price = newPrice;
	Notify(PRICE);
	return price;
}

void University::CancelLecture(const string& courseName) {
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
		for (int i = 0; i < m_observers.size(); i++)
			(m_observers[i])->Update(this);
	}
	else{
		for (int i = 0; i < m_observers.size(); i++){
			if (m_observers[i].getFaculty() == "ESF")
				(m_observers[i])->Update(this);
		}
	}
}

University::University(int iPrice):price(iPrice){}

