#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cout << "Enter a and b: ";
	cin >> a >> b;
	cout << "a+b=" << a + b << endl << "a-b=" << a - b << endl << "a*b=" << a * b << endl << "a/b=" << a / b << endl << endl;
	double c, d;
	cout << "Enter c and d: ";
	cin >> c >> d;
	cout << "c+d=" << c + d << endl << "c-d=" << c - d << endl << "c*d=" << c * d << endl << "c/d=" << c / d << endl << endl;
	cout << "a+d=" << a + d << endl << "a-d=" << a - d << endl << "a*d=" << a * d << endl << "a/d=" << a / d << endl << endl;
	cout << "c+b=" << c + b << endl << "c-b=" << c - b << endl << "c*b=" << c * b << endl << "c/b=" << c / b << endl << endl;
}
