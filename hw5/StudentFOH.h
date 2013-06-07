#ifndef STUDENTFOH_H
#define STUDENTFOH_H

#include "StudentImpl.h"

//class StudentImpl;
//class University;

class StudentFOH : public StudentImpl {
	friend class StudentFactory;
public:
    virtual ~StudentFOH() {}
    
    virtual const string& GetFaculty() const;

protected:
    StudentFOH(const string& name, University* sbj) : StudentImpl(name, sbj) {}
private:
    StudentFOH(const StudentFOH& other);
	StudentFOH& operator=(const StudentFOH rhs);

    static const string faculty;
};

#endif // STUDENTFOH_H
