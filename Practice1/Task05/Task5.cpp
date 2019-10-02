#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	double x, x0, v0, t, a = -9.8;
	cout << "Enter x0, v0 and t: " << endl;
	cin >> x0 >> v0 >> t;
	x = x0 + v0 * t + a * t*t / 2;
	cout << x << endl;
}
