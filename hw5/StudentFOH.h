//
//  StudentFOH.h
//  cpp-2013
//
//  Created by Ehud Tamir on 6/1/13.
//  Copyright (c) 2013 Ehud Tamir. All rights reserved.
//

#ifndef STUDENTFOH_H
#define STUDENTFOH_H

#include "StudentImpl.h"

class StudentFOH : public StudentImpl {
public:
    StudentFOH(const string& name) : StudentImpl(name) {}
    ~StudentFOH() {}
};

#include <iostream>

#endif // STUDENTFOH_H
