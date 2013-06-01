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

using namespace std;

class Subject;

class StudentImpl : public Observer {
public:
	StudentImpl(const string& name, Subject* sbj);
	virtual ~StudentImpl() = 0;
    virtual const string& GetName() const;
    virtual void Update(Subject* ChngSubject);
    virtual const string& asString() const;
private:
	const string& name;
    int price;
};

#endif /* STUDENTIMPL_H_ */
