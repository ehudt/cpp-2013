#include <cstddef>

class X {
private:
	void* operator new(size_t) { return (void*)0;}
	void operator delete(void *){}
};

class Y : public X {};


int main(void) {
	X x2;
	Y y1;
	//X* xp = new X;
	Y* yp = ::new Y;

	//delete xp;
	::delete yp;
	return 0;
}