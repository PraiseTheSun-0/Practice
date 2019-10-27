#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	
	int number, pow, result = 1, counter = 0;
	bool flag = 0;
	cin >> number;
	cin >> pow;
	if (!pow || number == 1) cout << result << endl;
	else if (pow < 0) {
		pow = -pow;
		flag = true;
	}
	while (!pow % 2) {
		counter++;
		pow /= 2;
	}
	for (int i = 0, result = number; i < counter; i++) result *= result;
	for (int k = 0; k < pow; k++)result *= number;
	if (flag)cout << 1.0 / result << endl;
	else cout << result << endl;
}
