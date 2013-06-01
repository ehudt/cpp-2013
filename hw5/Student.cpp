/*
 * Student.cpp
 *
 *  Created on: Jun 1, 2013
 *      Author: ehudt
 */

#include "Student.h"
#include "StudentImpl.h"

Student::Student(const string& faculty, const string& name) {
	m_Student = StudentFactory::Create(faculty, name);
}

Student::~Student() {
	delete m_Student;
	m_Student = 0;
}

void Student::Update(Subject* ChngSubject) const {
	m_Student->Update(ChngSubject);
}

const string& Student::GetName() const {
	return m_Student->GetName();
}
