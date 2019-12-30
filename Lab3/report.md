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

![](https://raw.githubusercontent.com/PraiseTheSun-0/Practice/master/Lab3/Lab3/Screenshot_1.png) 

Рис. 2. Ключ


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

Запустим программу с значениями `a = 0.7`, `b = 1.2`, `x1 = 0.5`, `x1 = 1.5`, `dx = 0.05`

![](https://raw.githubusercontent.com/PraiseTheSun-0/Practice/master/Lab2/Screenshots/Screenshot_01.png "Рис. 1. Ввод данных") 

Рис. 1. Ввод данных


![](https://raw.githubusercontent.com/PraiseTheSun-0/Practice/master/Lab2/Screenshots/Screenshot_02.png "Рис. 2. Результат")

Рис. 2. Результат

**x**|**y**
-----|-----
0.5|0.473849
0.55|0.492026
0.6|0.511165
0.65|0.531329
0.7|0.552588
0.75|0.274818
0.8|0.416856
0.85|0.559981
0.9|0.704649
0.95|0.851207
1.0|1.0
1.05|1.15129
1.1|1.30531
1.15|1.46226
1.2|0.0679609
1.25|0.0510154
1.3|0.0364418
1.35|0.0242766
1.4|0.0145503
1.45|0.00728701
1.5|0.00250501

Как мы видим, максимальное значение - `1.46226` при `x = 1.15`, а минимальное - `0.00250501` при `x = 1.5`.

![](https://raw.githubusercontent.com/PraiseTheSun-0/Practice/master/Lab2/Screenshots/Screenshot_03.png "Рис. 3. График функций с указанными максимальным и минимальным значением")

#### Вывод: мы приобрели навыки разработки и программирования вычислительного процесса циклической структуры, а так же навыки программирования структуры ветвления. Научились пользоваться оператором ветвления.