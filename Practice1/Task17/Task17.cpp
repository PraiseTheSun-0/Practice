#include "pch.h"
#include <iostream>

bool isEqual(double first, double second){
	double e = 0.00000001;
	return (abs(first - second) < e);
}

double BMI(double weight, double height) {
	return weight / (height * height);
}

void printBMI(double BMI) {
	if (BMI < 18.5)std::cout << "Underweight";
	else if ((isEqual(18.5, BMI) || 18.5 < BMI ) && BMI < 25.0)std::cout << "Normal";
	else if ((isEqual(25.0, BMI) || 25.0 < BMI ) && BMI < 30.0)std::cout << "Overweight";
	else std::cout << "Obesity";
}

int main()
{
	double a, b;
	std::cin >> a >> b;
	b /= 100;
	double bmi = BMI(a, b);
	printBMI(bmi);
}
