#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	double a, b;
	cout << "Enter a and b: ";
	cin >> a >> b;
	cout << "a=" << a << "; b=" << b << endl;
	double temp;
	temp = a;
	a = b;
	b = temp;
	cout << "a=" << a << "; b=" << b << endl;
	b = b + a;
	a = b - a;
	b = b - a;
	cout << "a=" << a << "; b=" << b << endl;
}
