#include "pch.h"
#include <iostream>
#include <ctime>

int main()
{
	srand(time(0));
	int max = -100, min = 100, a[20];
	for (int i = 0; i < 20; i++) a[i] = rand() % 201 - 100;
	for (int i = 0; i < 20; i++)
	{
		std::cout << a[i] << ' ';
		if (a[i] > max)max = a[i];
		if (a[i] < min)min = a[i];
	}
	std::cout << std::endl << min << std::endl << max;
}
