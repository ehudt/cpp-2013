#include "memPool_t.h"
#include <string.h>
#include <iostream>
using namespace std;

int main(void) {
	int x = 500;
	char s1[] = "This is a regular C string.";
	double d1[] = {3.1415, 1.4142, 2.71828, 0.3678, 1.618};

	cout << "Writing the following data structures into memory pool:" << endl;
	cout << "An int: " << x << endl;
	cout << "A C-string: " << s1 << endl;
	cout << "An array of doubles: ";
	for (int i = 0; i < (int)(sizeof(d1)/sizeof(double)); ++i) {
		cout << d1[i] << " ";
	}
	cout << endl;

	memPool_t pool;
	pool.write(&x, sizeof(x));
	pool.write(s1, sizeof(s1));
	pool.write(d1, sizeof(d1));

	int y;
	char s2[sizeof(s1)];
	double d2[5];

	cout << endl << "Reading the data back from memory pool:" << endl;
	pool.setPosition(0);
	pool.read(&y, sizeof(y));
	pool.read(s2, sizeof(s2));
	pool.read(d2, sizeof(d2));

	cout << "The int: " << y << endl;
	cout << "The C-string: " << s2 << endl;
	cout << "The array of doubles: ";
	for (int i = 0; i < (int)(sizeof(d2)/sizeof(double)); ++i) {
		cout << d2[i] << " ";
	}
	cout << endl;

	return 0;
}
