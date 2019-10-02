#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int answer, userAnswer, restart, counter;
	bool flag;
	do {
		answer = rand() % 101;
		//Для проверки раскоментировать строку ниже
		//cout << "Правильный ответ: " << answer << endl;
		counter = 0;
		flag = false;
		cout << "Попробуйте угадать число от 0 до 100 включительно" << endl;
		do {
			cin >> userAnswer;
			if (userAnswer >= 0 && userAnswer <= 100) {
				if (userAnswer == answer) {
					cout << "Поздравляю! Вы угадали" << endl;
					flag = true;
				}
				else if (userAnswer < answer) {
					counter++;
					if (counter == 5) {
						cout << "Вы проиграли. Было загадано: " << answer << endl;
						flag = true;
						break;
					}
					cout << "Загаданное число больше" << endl;	
				}
				else {
					counter++;
					if (counter == 5) {
						cout << "Вы проиграли. Было загадано: " << answer << endl;
						flag = true;
						break;
					}
					cout << "Загаданное число меньше" << endl;					
				}
			}
			else { 
				cout << "Диапазон от 0 до 100" << endl;
				flag = true;
			}
		} while (flag != true);
		cout << "Хотите начать сначала? (1 - Да)" << endl;
		cin >> restart;
	} while (restart == 1);
}
