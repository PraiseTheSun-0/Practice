﻿#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int number, result = 1;
	cin >> number;
	for (int i = 1; i <= number; i++) {
		result *= i;
	}
	cout << result << endl;
}