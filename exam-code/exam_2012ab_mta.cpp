#include <cmath>
#include <iostream>

using namespace std;

class Point
{
public:
	Point(double x = 0, double y = 0) { cout << "I shit on you " << x << " " << y << endl; }
private:
	double m_X, m_Y;
};

int main(void) {
	double a, r, x, y;
	cout << a << " " << r << " " << x << " " << y << " " << endl;
	Point p = (x + r * cos(a), y + r * sin(a));
	return 0;
}