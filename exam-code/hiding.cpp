#include <iostream>
#include <string> 
#include <cstdio>

using namespace std;
#define print(c) do { cout << c << endl; } while(0)


class Base {
public:
	virtual ~Base() {}
	void foo() const { print ("Base");}

};

class Drv : public Base {
public:
	 void foo() const { print ("Drv");}
};

void func(Base& obj) {
	//print (typeid(obj).name());
	obj.foo();
	//Drv& d = *(dynamic_cast<Drv*>(&obj));
	//d.foo();
}



class Base2 {
public:
	virtual void func(double f) { cout << "Base2 func" << endl; }
};

class Derived : public Base2 {
public:
	using Base2::func;
	virtual void func(int i) { cout << "Derived func" << endl; }
	//void func(float f) { Base2::func(f); }
};

void timtum() {
	Derived d;
	d.func(3.14);
}

int main(void) {
	//Drv d;
	//d.foo();
	//func(d);
	timtum();
	return 0;
}