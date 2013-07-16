#include <iostream>

using namespace std;

double max(int a, int b, int c) {
	cout << "max 1" << endl;
	return a > b ? a : b;
}

double max(double a, double b, double c) {
	cout << "max 2" << endl;
	return a > b ? a : b;
}

int main(void) {
	cout << max(6.1, 3.1, 2.1) << endl;
	return 0;
}