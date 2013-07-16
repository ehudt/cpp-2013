#include <string>
#include <iostream>

using namespace std;


int main(void) {
	try {
		throw;
	} catch (...) {
		cout << "rikavon" << endl;
	}
	return 0;
}