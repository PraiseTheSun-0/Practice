#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int number, counter = 0;
	cin >> number;
	for (int i = 1; i < number; i++) {
		if (number%i == 0) counter++;
		if (counter > 1) {
			cout << "Составное" << endl;
			break;
		}
	}
	if (counter <= 1)cout << "Простое" << endl;
}
