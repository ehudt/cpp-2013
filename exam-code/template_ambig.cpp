#include <iostream>

using namespace std;
#define print(c) do { cout << c << endl; } while(0)

void foo(int n) { print("Non-Template"); }

template <class T>
void foo(T t) { print("Template"); }

int main(void) {
	foo(5);
	return 0;
}