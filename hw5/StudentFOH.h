#ifndef STUDENTFOH_H
#define STUDENTFOH_H

#include "StudentImpl.h"

class StudentFOH : public StudentImpl {
public:
    StudentFOH(const string& name, Subject* sbj) : StudentImpl(name, sbj) {}
    ~StudentFOH() {}
};

#include <iostream>

#endif // STUDENTFOH_H
