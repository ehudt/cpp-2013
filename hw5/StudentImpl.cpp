/*
 * StudentImpl.cpp
 *
 *  Created on: Jun 1, 2013
 *      Author: ehudt
 */

#include <iostream>
#include "StudentImpl.h"
#include "Subject.h"

using namespace std;

StudentImpl::StudentImpl(const string& name, Subject* sbj)
    : name(name),
      price(-1),
      Observer(sbj) {
          sbj->Attach(this);
}

StudentImpl::~StudentImpl() {
    sbj->Detach(this);
}

const string& StudentImpl::GetName() const {
    return name;
}

void StudentImpl::Update(Subject* ChngSubject) {
    if (ChngSubject == sbj) {
        University& uni = *(University*)ChngSubject;
        if (uni->GetPrice() != price) {
            price = uni->GetPrice();
            cout << this->asString() << " was updated of a new price:"
                << price << "." << endl;
        }
    }
}

const string& StudentImpl::asString() const {
    return name;
}