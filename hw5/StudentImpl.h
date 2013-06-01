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
	StudentImpl();
	virtual ~StudentImpl();
private:
	const string& name;
};

#endif /* STUDENTIMPL_H_ */
