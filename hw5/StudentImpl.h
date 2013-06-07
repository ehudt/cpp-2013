/*
 * StudentImpl.h
 *
 *  Created on: Jun 1, 2013
 *      Author: ehudt
 */

#ifndef STUDENTIMPL_H_
#define STUDENTIMPL_H_

#include <string>
#include "Observer.h"
#include "University.h"

using namespace std;

class University;

class Subject;

class StudentImpl : public Observer {
public:
	StudentImpl(const string& name, University* sbj);
	virtual ~StudentImpl() = 0;
    virtual const string& GetName() const;
    virtual const string& GetFaculty() const = 0;
    virtual void Update(Subject* ChngSubject);
    virtual const string asString() const;
    virtual University* GetUni() const;
protected:
    University* uni;
private:
	const string name;
    size_t price;
};

#endif /* STUDENTIMPL_H_ */
