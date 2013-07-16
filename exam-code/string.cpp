#include <string>
#include <iostream>
using namespace std;

string foo() {
	string res("abc");
	return res;
}

int main(void) {
	string& s = (foo());
	cout << s << endl;
	string& s2 = *(new string());
	delete &s2;
	return 0;
}