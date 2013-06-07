#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <vector>

using namespace std;

class Observer;

class Subject {
public:
	virtual ~Subject() {}

    virtual void Attach(Observer*);
    virtual void Detach(Observer*);
    virtual void Notify();
protected:
	Subject() {}
	vector<Observer*> m_observers;
};

#endif /* SUBJECT_H_ */
