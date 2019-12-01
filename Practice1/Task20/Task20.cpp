#include "pch.h"
#include <iostream>

void sort(int *a, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		int counter = 0;
		for (int k = 0; k < length - i - 1; k++)
			if (a[k] > a[k + 1])
			{
				int temp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = temp;
				counter++;
			}
		if(!counter)break;
	}
}

void cOut(int *a, int length)
{
	for (int i = 0; i < length; i++)std::cout << a[i] << ' ';
}

int main()
{
	int n;
	std::cin >> n;
	int *array = new int[n];
	for (int i = 0; i < n; i++)std::cin >> array[i];
	sort(array, n);
	cOut(array, n);
}
