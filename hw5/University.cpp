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
	Notify();
	return price;
}

void University::CancelLecture(string& courseName) {
	Notify(courseName);//TODO
}

University::University(int iPrice):price(iPrice){}

