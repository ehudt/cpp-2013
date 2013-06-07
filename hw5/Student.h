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

using namespace std;

class StudentImpl;
//class Subject;
class University;

class Student : public Observer {
public:
	Student(const string& faculty, const string& name, University* sbj);
	virtual ~Student();
	virtual void Update(const Subject* ChngSubject);
	virtual const string& GetName() const;
    virtual const string& GetFaculty() const;
protected:
	StudentImpl* m_Student;
private:
	Student(const Student& other);
	Student& operator = (const Student& rhs);
};

#endif /* STUDENT_H_ */
