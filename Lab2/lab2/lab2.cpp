#include "pch.h"
#include <iostream>
#include "math.h"
using namespace std;

bool isEqual(double a, double b) {
	double e = 0.00000001;
	return (abs(a - b) < e);
}

int main() {
	setlocale(LC_ALL, "Russian");
	double a, b, x1, x2, dx, y, x;
	cout << "Введите a, b, начало промежутка, конец промежутка, dx" << endl;
	cin >> a >> b >> x1 >> x2 >> dx;
	if (!dx) {
		cout << "Шаг не может быть нулём" << endl;
		return 0;
	}
	if (x1 > x2 && dx > 0 || x2 > x1 && dx < 0) {
		cout << "С выбранным шагом нельзя прийти из начала в конец" << endl;
		return 0;
	}
	for (x = x1; x < x2 || isEqual(x, x2); x += dx) {	
		if (x >= x1 && x < a || isEqual(x, a)) {
			y = exp(x) / (3.0 + sin(x));
		}
		else if (x > a && x < b) {
			y = log(x) + x * x;
		}
		else {
			y = 1.0 + sin(-x);
		}
		cout << "При х = " << x << ", y = " << y << endl;
	}
}