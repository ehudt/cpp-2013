#ifndef OBSERVER_H_
#define OBSERVER_H_

class Subject;

class Observer {
public:
	virtual			~Observer() {}
    virtual void	Update(Subject* ChngSubject) = 0;
protected:
	Observer(Subject* sbj) : sbj(sbj) {}
	Subject* sbj;
};

#endif /* OBSERVER_H_ */
