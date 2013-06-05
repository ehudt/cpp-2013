/*
 * StudentFactory.cpp
 *
 *  Created on: Jun 5, 2013
 *      Author: arbel
 */

#include "StudentFactory.h"
#include "StudentESF.h"
#include "StudentFOH.h"

Student* StudentFactory::Create(const string& type, const string& name) {
	Student* ptrStudent = 0;
	  		if (type == "ESF")
				ptrStudent = new StudentESF(name);
	  		if (type == "FOH")
				ptrStudent = new StudentFOH(name);
			return ptrStudent;
}

