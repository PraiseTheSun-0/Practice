﻿#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int number, pow, result = 1;
	cin >> number;
	cin >> pow;
	for (int i = 1; i <= pow; i++) {
		result *= number;
	}
	cout << result << endl;
}
