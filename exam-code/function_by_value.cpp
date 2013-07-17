#include <iostream>
#include <string> 
#include <cstdio>

using namespace std;
#define print(c) do { cout << c << endl; } while(0)

class A {
public:
	virtual ~A() {}
	virtual void me() {print("Base::me()");}
private:
	int a;
};

class B : public A {
public:
	virtual void me() {print("Derived::me()");}
private:
	int b;
};

void foo(A& a) {
	a.me();
	B* b = dynamic_cast<B*>(&a);
	if (b) print("Derived");
	else print("Base");
	print (typeid(a).name());
	print (typeid(&a).name());
}

class Base {
public:
	virtual ~Base() {}
	void foo() const { print ("Base");}

};

class Drv : public Base {
public:
	 void foo() const { print ("Drv");}
};

void func( Base* obj) {
	print (typeid(*obj).name());
	obj->foo();
}

int main(void) {
	Drv d;
	func(&d);
	unsigned ** p = (unsigned **)&d;
	cout << *p << (*p + 1) << (*p + 2) << (*p + 3)  << endl;
	Base b;
	p = (unsigned **)&b;
	cout << *p << (*p + 1) << (*p + 2) << (*p + 3)  << endl;
	//Base a;
	//func(a);
	/*B b;
	A a;
	//a.me();
	A* pa = new A;
	B* pb = new B;
	print (typeid(pa).name());
	print (typeid(pb).name());
	
	print (typeid(a).name());
	foo(a);
	
	//b.me();
	print (typeid(b).name());
	foo(b);*/
/*
	FILE* fp = fopen("file.tmp", "w+");
	print(fwrite("ehud", 1, 4, fp));
	print(fclose(fp));
	print(fwrite("ehud", 1, 4, fp));
	print(fclose(fp));
*/

	
	return 0;
}