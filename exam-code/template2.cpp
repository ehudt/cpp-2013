#include <iostream>
#include <vector>
using namespace std;

#define print(c) do { cout << c << endl; } while(0)

template <typename T>
class A {
public:
	void foo(T t) {print(t);}
};

template <typename T>
void func() {
	A<T> a;
	a.foo(T());
}

int main(void ) {
	func<long long>();
	return 0;
}

template <class T>
T min (const T t1, const T t2) {
	return (t1 < t2) ? t1 : t2;
}