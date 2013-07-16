#include <iostream>

using namespace std;

class Pointer {
public:
	Pointer(int n) {
		p = new int;
		*p = n;
	}
	~Pointer() { delete p; }
	operator int * () const { return p; }
	operator int () const { return *p; }
	int* GetP() const { return p; }
private:
	int* p;
};

int main(void) {
	Pointer pp(17);
	int* p = pp;
	int n = pp;
	cout << p << ", " << n << endl;
	cout << pp.GetP() << endl;
	cout << static_cast<int *>(pp) << ", " << static_cast<int>(pp) << endl;
	cout << pp.operator int *() << endl;
	string s1("ehud");
	string s2("roi");
	cout << s1.operator char *() << ", " << s2.operator char *() << endl;
	//cout << s1 - s2 << endl;
	return 0;
}