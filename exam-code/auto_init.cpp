#include <iostream>

using namespace std;

class NoCTOR {
public:
	int GetN() const { return n; }
	char* GetS() const { return s; }
private:
	int n;
	char* s;
};

int main(void) {
	NoCTOR nc;
	cout << nc.GetN() << ", " << (void *)nc.GetS() << endl;
	return 0;
}