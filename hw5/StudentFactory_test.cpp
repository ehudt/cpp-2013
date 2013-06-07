/*
 * StudentFactory_test.cpp
 *
 *  Created on: Jun 7, 2013
 *      Author: ehudt
 */

#include <assert.h>

#include "StudentFactory.h"
#include "University.h"
#include "StudentImpl.h"

void testStudentFactory() {
	University& uni = University::GetObj();
	StudentImpl* student;
	student = StudentFactory::Create("FOH", "Arbel", &uni);
	assert(student != 0);
	assert(student->GetFaculty() == "FOH");
	assert(student->GetName() == "Arbel");

	student = StudentFactory::Create("ESF", "Ehud", &uni);
	assert(student != 0);
	assert(student->GetFaculty() == "ESF");
	assert(student->GetName() == "Ehud");

	student = StudentFactory::Create("No Existent Faculty", "Dani Dean", &uni);
	assert(student == 0);
}

int main(void) {
	testStudentFactory();
	return 0;
}

