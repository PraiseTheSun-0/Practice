#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, result;
	char S;
	cin >> a >> S >> b;
	if (S != '+' && S != '-' && S != '*' && S != '/')cout << "Используйте один из знаков: + - * /" << endl;
	else {
		switch (S) {
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result = a / b;
			break;
		}
		cout << result << endl;
	}
}