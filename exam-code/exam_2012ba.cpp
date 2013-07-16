#include <string>
#include <iostream>

using namespace std;

class NoHeap {
protected:
	static void* operator new(size_t sz) {
		return (void*)0;
	}
	static void* operator new[](size_t sz) {
		return (void*)0;
	}
};

class NoStack {
public:
	void Destroy() {
		delete this;
	}
protected:
	~NoStack() {}

};

class Overload {
public:

	friend ostream& operator <<(ostream& os, const Overload& o) {
		return os << o.a;
	}
	friend Overload operator +(const Overload& x, const Overload& y) {
		cout << "friend +" << endl;
		return Overload(x.a + y.a);
	}
	Overload(int a) : a(a) {}
	/*Overload operator +(const Overload& rhs) const {
		cout << "member +" << endl;
		return Overload(a + rhs.a);
	}*/
private:
	int a;
};


int main(void) {
	//NoStack ns; // Illegal
	NoStack* pns = new NoStack();
	NoHeap nh;
	//NoHeap* pnh = new NoHeap();
	Overload o1(5);
	int a = 7;
	cout << o1 + a << endl;
	cout << a + o1 << endl;
	cout << operator + (o1, a) << endl;
	return 0;
}