МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 3<br/> по дисциплине "Программирование"
<br/>

студента 1 курса группы 191(1)  
Балабанова Никиты Петровича  
направления подготовки 09.03.04 "Программная инженерия"  
<br/>

<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>

Симферополь, 2019
 
 **Цель работы:**
 - **Закрепить навыки разработки программ использующих операторы цикла;**
 - **Закрепить навыки разработки программ использующих массивы;**
 - **Освоить методы подключения сторонних библиотек.**

#### Ход рыботы

![](https://raw.githubusercontent.com/PraiseTheSun-0/Practice/master/Lab3/Lab3/pic1.bmp) 

Рис. 1. Картинка для декодирования

![](https://raw.githubusercontent.com/PraiseTheSun-0/Practice/master/Lab3/Lab3/Screenshots/Screenshot_1.png) 

Рис. 2. Ключ

![](https://raw.githubusercontent.com/PraiseTheSun-0/Practice/master/Lab3/Lab3/Screenshots/Screenshot_2.png)

Рис. 3. Создаём include с libbmp.h

![](https://raw.githubusercontent.com/PraiseTheSun-0/Practice/master/Lab3/Lab3/Screenshots/Screenshot_3.png)

Рис. 4. Добавляем и подключаем библиотеку

Напишем программу для выполенения поставленной задачи:

```c++
#include "libbmp.h"
#include <iostream>

int main()
{
	BmpImg img;
	img.read("pic1.bmp");
	const int width = img.get_width() - 1;
	const int height = img.get_height() - 1;
	char code[3000];
	char y = 0;
	int code_position = 0;
	int counter = 0;
	int Bit;
	bool broken = false;
	for (int i = height; i >= 0; i--)
	{
		for (int k = width; k >= 0; k--)
		{
			Bit = img.red_at(k, i);
			y = y << 1;
			if (Bit % 2 == 1) y++;
			counter++;
			if (counter == 8) {
				code[code_position] = y;
				code_position++;
				counter = 0;
				if (y == '\0') {
					broken = true;
					break;
				}
			}
			Bit = img.green_at(k, i);
			y = y << 1;
			if (Bit % 2 == 1) y++;
			counter++;
			if (counter == 8) {
				code[code_position] = y;
				code_position++;
				counter = 0;
				if (y == '\0') {
					broken = true;
					break;
				}
			}
			Bit = img.blue_at(k, i);
			y = y << 1;
			if (Bit % 2 == 1) y++;
			counter++;
			if (counter == 8) {
				code[code_position] = y;
				code_position++;
				counter = 0;
				if (y == '\0') {
					broken = true;
					break;
				}
			}
		}
		if (broken)	break;
	}
	std::cout << code;
}
```

Запустим программу и получим следующее сообщение: 

![](https://raw.githubusercontent.com/PraiseTheSun-0/Practice/master/Lab3/Lab3/Screenshots/Screenshot_4.png)

Рис. 5. Вывод

#### Вывод: я закрепил навыки разработки программ использующих операторы цикла, массивы, освоил методы подключения сторонних библиотек.