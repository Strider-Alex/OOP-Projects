#include <string>
#include <iostream>
#include"fraction.h"
using namespace std;
int main() {
	Fraction x, y;
	cout << "Enter x(?/?): ";
	cin >> x;
	cout << "Enter y(?/?): ";
	cin >> y;
	cout << "double(x) = " << double(x) << endl;
	cout << "double(y) = " << double(y) << endl;
	cout << "x + y = " << x + y << endl;
	cout << "x - y = " << x - y << endl;
	cout << "x * y = " << x * y << endl;
	cout << "x / y = " << x / y << endl;
	cout << "x == y: " << (x == y) << endl;
	cout << "x != y: " << (x != y) << endl;
	cout << "x < y: " << (x < y) << endl;
	cout << "x > y: " << (x > y) << endl;
	cout << "x <= y: " << (x <= y) << endl;
	cout << "x >= y: " << (x >= y) << endl;
}