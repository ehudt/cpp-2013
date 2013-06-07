#ifndef STUDENTFOH_H
#define STUDENTFOH_H

#include "StudentImpl.h"

class StudentFOH : public StudentImpl {
public:
    StudentFOH(const string& name, University* sbj) : StudentImpl(name, sbj) {}
    ~StudentFOH() {}
    
    virtual const string& GetFaculty() const;

private:
    static const string faculty;
};

#endif // STUDENTFOH_H