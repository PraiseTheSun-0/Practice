#include "pch.h"
#include <iostream>
#include <vector>

void factorization(int n) {
	std::vector<int> A;
	int counter = 0;
	int pow = 1;
	while (n != 1) {
		for (int i = 2; i <= n; i++) {
			if (!(n%i)) {
				n /= i;
				A.push_back(i);
				counter++;
				break;
			}
		}
	}
	for (auto it = A.begin(); it != A.end(); it++) {
		if (it != A.end() - 1  && *it == *(it + 1))pow++;
		else if (pow>1) {
			std::cout << *it << "^" << pow;
			pow = 1;
		}
		else std::cout << *it;
		if ((it != A.end() - 1) && (pow<=1))std::cout << "*";
	}
}
int main()
{
	int a;
	std::cin >> a;
	factorization(a);	
}
