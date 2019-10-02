#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c, D, x1, x2;
	cin >> a;
	cin >> b;
	cin >> c;
	if (a == 0 && b == 0) {
		cout << "x - любое число" << endl;
	}
	else if (a == 0 && c == 0 || b == 0 && c == 0) {
		x1 = 0;
		cout << "x = " << x1 << endl;
	}
	else if (a == 0) {
		x1 = -c / b;
		cout << "x = " << x1 << endl;
	}
	else if (b == 0) {
		if (-c < 0)cout << "Нет действительных корней уравнения" << endl;
		else {
			x1 = sqrt(-c / a);
			x2 = -sqrt(-c / a);
			cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
		}
	}
	else if (c == 0) {
		x1 = 0;
		x2 = -b / a;
		cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl;
	}else{
		D = b * b - 4 * a * c;
		if (D < 0) {
			cout << "Нет действительных корней уравнения" << endl;
		}
		else if (D == 0) {
			cout << "x = " << -b / (2 * a) << endl;
		}
		else {
			cout << "x1 = " << (-b + sqrt(D)) / (2 * a) << endl;
			cout << "x2 = " << (-b - sqrt(D)) / (2 * a) << endl;
		}
	}
}