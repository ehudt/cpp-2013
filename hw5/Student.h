/*
 * Student.h
 *
 *  Created on: Jun 1, 2013
 *      Author: ehudt
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

#include "Observer.h"
#include "StudentFactory.h"

using namespace std;

class StudentImpl;
class Subject;

class Student : public Observer {
public:
	Student(const string& faculty, const string& name);
	virtual ~Student();
	virtual void Update(Subject* ChngSubject) const;
	virtual const string& GetName() const;
protected:
	StudentImpl* m_Student;
};

#endif /* STUDENT_H_ */
