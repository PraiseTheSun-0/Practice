#include <iostream>
#include <vector>
#include <time.h>

enum Order{ASC, DESC};

void BozoSort(int* a, int size, Order sort = ASC)
{
	bool sorted = false;
	int toSwap1, toSwap2;
	while (!sorted)
	{
		toSwap1 = rand() % size;
		do
		{
			toSwap2 = rand() % size;
		} while (toSwap2 == toSwap1);
		std::swap(a[toSwap1], a[toSwap2]);
		sorted = true;
		if (sort == ASC)
		{
			for (int k = 0; k < size - 1; k++) {
				if (a[k] > a[k + 1])
				{
					sorted = false;
					break;
				}
			}
		}
		else 
		{
			for (int k = 0; k < size - 1; k++) {
				if (a[k] < a[k + 1]) {
					sorted = false;
					break;
				}
			}
		}
	}
}

void BozoSort(std::vector<int> &a,int size, Order sort = ASC)
{

	bool sorted = false;
	int toSwap1, toSwap2;
	while (!sorted)
	{
		toSwap1 = rand() % size;
		do
		{
			toSwap2 = rand() % size;
		} while (toSwap2 == toSwap1);
		std::swap(a[toSwap1], a[toSwap2]);
		sorted = true;
		if (sort == ASC)
		{
			for (int k = 0; k < size - 1; k++) {
				if (a[k] > a[k + 1])
				{
					sorted = false;
					break;
				}
			}
		}
		else
		{
			for (int k = 0; k < size - 1; k++) {
				if (a[k] < a[k + 1]) {
					sorted = false;
					break;
				}
			}
		}
	}
}

void BozoSort(int *a, int *b, int *c, Order sort = ASC)
{
	int arr[] = { *a,*b,*c };
	bool sorted = false;
	int toSwap1, toSwap2;
	while (!sorted)
	{
		toSwap1 = rand() % 3;
		do
		{
			toSwap2 = rand() % 3;
		} while (toSwap2 == toSwap1);
		std::swap(arr[toSwap1], arr[toSwap2]);
		sorted = true;
		if (sort == ASC)
		{
			for (int k = 0; k < 2; k++) {
				if (arr[k] > arr[k + 1])
				{
					sorted = false;
					break;
				}
			}
		}
		else
		{
			for (int k = 0; k < 2; k++) {
				if (arr[k] < arr[k + 1]) {
					sorted = false;
					break;
				}
			}
		}
	}
	*a = arr[0], *b = arr[1], *c = arr[2];
}

int main()
{
	srand(time(0));
	int x, first, second, third;
	std::cin >> x;
	int* arr = new int[x];
	std::vector<int> vec;
	for (int i = 0; i < x; i++) {
		std::cin >> arr[i];
		vec.push_back(arr[i]);
	}
	first = arr[0], second = arr[1], third = arr[2];
	
	std::cout << "Array: " << std::endl;
	BozoSort(arr, x);
	for (int i = 0; i < x; i++) std::cout << arr[i]<<' ';
	std::cout << std::endl;
	BozoSort(arr, x, DESC);
	for (int i = 0; i < x; i++) std::cout << arr[i]<<' ';
	std::cout << std::endl;
	
	std::cout << "Vector: " << std::endl;
	BozoSort(vec,x);
	for (int i = 0; i < x; i++) std::cout << vec[i] << ' ';
	std::cout << std::endl;
	BozoSort(vec,x, DESC);
	for (int i = 0; i < x; i++) std::cout << vec[i] << ' ';
	std::cout << std::endl;

	std::cout << "Numbers: " << std::endl;
	BozoSort(&first, &second, &third);
	std::cout << first << ' '<<second << ' '<<third << ' ';
	std::cout << std::endl;
	BozoSort(&first, &second, &third,DESC);
	std::cout << first << ' ' << second << ' ' << third << ' ';
	delete[] arr;
}
