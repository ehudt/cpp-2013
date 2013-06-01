/*
 * StudentImpl.h
 *
 *  Created on: Jun 1, 2013
 *      Author: ehudt
 */

#ifndef STUDENTIMPL_H_
#define STUDENTIMPL_H_

class StudentImpl : public Observer {
public:
	StudentImpl() {};
	virtual ~StudentImpl() = 0;
    virtual const string& GetName()const;
    virtual void Update(Subject* ChngSubject);
private:
	const string& name;
};

#endif /* STUDENTIMPL_H_ */
