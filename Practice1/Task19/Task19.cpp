#include "pch.h"
#include <iostream>

int main()
{
	int number, n, a[10]={0};
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> number;
		a[number]++;
	}
	for (int i = 0; i < 10; i++) if (a[i])std::cout << i << ": " << a[i] << std::endl;
}
