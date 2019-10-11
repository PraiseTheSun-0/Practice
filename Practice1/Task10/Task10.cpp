#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	/*int number, pow, result = 1;
	cin >> number;
	cin >> pow;
	for (int i = 1; i <= pow; i++) {
		result *= number;
	}
	cout << result << endl;*/
	int number, pow, result = 1, counter = 0;
	cin >> number;
	cin >> pow;
	if (pow < 0)cout << "Введите неотрицательную степень" << endl;
	else if (!pow || number == 1) cout << result << endl;
	else {
		while (!pow % 2) {
			counter++;
			pow /= 2;
		}
		for (int i = 0, result = number; i < counter; i++) result *= result;
		for (int k = 0; k < pow; k++)result *= number;
		cout << result << endl;
	}
}
