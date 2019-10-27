#include "pch.h"
#include <iostream>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int counter = 0, a, b;
	int arr[10][8] = { 0 };
	arr[rand() % 10][rand() % 8]--;
	//Для проверки раскоментируйте блок ниже
	/*for(int i = 0; i<10;i++)
		for(int k = 0; k<8;k++)	if (arr[i][k])std::cout << i << ' ' << k << std::endl;*/
	while (counter < 5)
	{
		std::cin >> a >> b;
		if (a >= 10 || a < 0 || b < 0 || b >= 8) {
			std::cout << "Выход за границу массива" << std::endl;
			continue;
		}
		if (arr[a][b] == -1)
		{
			std::cout << "Вы угадали";
			return 0;
		}
		else if (!arr[a][b]) {
			std::cout << "Нет" << std::endl;
			arr[a][b]++;
			counter++;
		}
		else std::cout << "Эту уже проверяли" << std::endl;
	}
	std::cout << "GAME OVER" << std::endl;
}
