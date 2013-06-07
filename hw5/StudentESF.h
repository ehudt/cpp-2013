#ifndef STUDENTESF_H
#define STUDENTESF_H

#include <string>

#include "StudentImpl.h"

using namespace std;

class Subject;

class StudentESF : public StudentImpl {
    StudentESF(const string& name, Subject* sbj) : StudentImpl(name, sbj) {}
    ~StudentESF() {}
};

#endif // STUDENTESF_H
