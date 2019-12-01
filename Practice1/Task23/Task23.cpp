#include "pch.h"
#include <iostream>

bool isNumber(int i)
{
	if (i >= 48 && i <= 57)return true;
	return false;
}

bool isLetter(int i)
{
	if ((i >= 65 && i <=90) || (i >= 97 && i <= 122))return true;
	return false;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char a[21], b[21] = {0};
	std::cin.getline(a, 21);
	for (int i = 0, n = 0; i < strlen(a); i++)
		if (isNumber((int)a[i]) || isLetter((int)a[i])) {
			b[n] = a[i];
			n++;
		}
	bool flag = true;
	int length = strlen(b);
	if (length) {
		for (int l = 0; l < length / 2; l++) {
			if (isNumber((int)b[l]) && b[l] != b[length - 1 - l]) {
				flag = false;
				break;
			}
			else if ((int)b[l] != (int)b[length - 1 - l] && (int)b[l] + 32 != (int)b[length - 1 - l] && (int)b[l] - 32 != (int)b[length - 1 - l]) {
				flag = false;
				break;
			}
		}
	}
	else flag = false;
	if(flag) std::cout << "Палиндром";
	else std::cout << "Не палиндром";
}
