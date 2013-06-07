#ifndef STUDENTESF_H
#define STUDENTESF_H

#include <string>

#include "StudentImpl.h"

using namespace std;

class Subject;

class StudentESF : public StudentImpl {
public:
    StudentESF(const string& name, University* sbj) : StudentImpl(name, sbj) {}
    ~StudentESF() {}

    virtual const string& GetFaculty() const;
    virtual void Update(Subject* ChngSubject);

private:
    string cancel_message;
    static const string faculty;
};

#endif // STUDENTESF_H
