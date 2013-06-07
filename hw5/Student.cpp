/*
 * Student.cpp
 *
 *  Created on: Jun 1, 2013
 *      Author: ehudt
 */

#include "Student.h"
#include "StudentImpl.h"
#include "StudentFactory.h"

Student::Student(const string& faculty, const string& name, University* sbj) {
	m_Student = StudentFactory::Create(faculty, name, sbj);
	m_Student->GetUni()->Attach(this);
}

Student::~Student() {
	m_Student->GetUni()->Detach(this);
	delete m_Student;
	m_Student = 0;
}

void Student::Update(Subject* ChngSubject) {
	m_Student->Update(ChngSubject);
}

const string& Student::GetName() const {
	return m_Student->GetName();
}

const string& Student::GetFaculty() const {
    return m_Student->GetFaculty();
}
