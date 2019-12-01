#include "pch.h"
#include <iostream>


void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int msort(int* a, int* b, int* c)
{
	if (*b > *a)swap(*&a, *&b);
	if (*c > *b)swap(*&c, *&b);
	if (*a > *c)swap(*&a, *&c);
	return *c;
}

void info (const int* a)
{
	std::cout << "Адрес: " << a << ";\nЗначение: " << *a << std::endl;
}

int* add(int* a, const int* b)
{
	int sum = *a + *b;
	*a = sum;
	return *&a;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int num1 = 3, num2 = 2, num3 = 1;
	info(&num1);
	info(&num2);
	info(&num3);
	std::cout << "Максимум: " << msort(&num1, &num2, &num3) << std::endl;
	add(&num1, add(&num2, &num3));
	info(&num1);
}
