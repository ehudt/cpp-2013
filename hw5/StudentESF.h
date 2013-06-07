#ifndef STUDENTESF_H
#define STUDENTESF_H

#include <string>
#include <iostream>
#include "StudentImpl.h"

using namespace std;

class Subject;
class StudentFactory;
//class StudentImpl;
//class University;

class StudentESF : public StudentImpl {
	friend class StudentFactory;
public:
    ~StudentESF() {}

    virtual const string& GetFaculty() const;
    virtual void Update(Subject* ChngSubject);

protected:
    StudentESF(const string& name, University* sbj) : StudentImpl(name, sbj), cancel_message("") {}

private:
    StudentESF(const StudentESF& other);
    StudentESF& operator=(const StudentESF rhs);
    string cancel_message;
    static const string faculty;
};

#endif // STUDENTESF_H
