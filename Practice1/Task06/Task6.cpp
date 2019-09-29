#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c, D;
	cin >> a;
	cin >> b;
	cin >> c;
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