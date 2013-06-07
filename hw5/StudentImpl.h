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

class Subject;

class StudentImpl : public Observer {
public:
	StudentImpl(const string& name, University* sbj);
	virtual ~StudentImpl() = 0;
    virtual const string& GetName() const;
    virtual const string& GetFaculty() const = 0;
    virtual void Update(Subject* ChngSubject);
    virtual const string asString() const;
private:
	const string& name;
    int price;
    University* uni;
};

#endif /* STUDENTIMPL_H_ */
