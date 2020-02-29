МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 7<br/> по дисциплине "Программирование"
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

#### Цель: изучить основные возможности создания и отладки программ в IDE Qt Creator.

1) Чтобы создать консольное приложение C++ без использования компонентов Qt, нужно в IDE Qt на верхней панели нажать `Файл -> Создать Файл или Проект -> Проект без Qt -> Приложение на языке С++`.

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_1.png?raw=true)
Рис. 1. Создаём проект

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_2.png?raw=true)
Рис. 2. Выбираем Проект без Qt

2) Чтобы поменять тему нужно нажать `Инструменты -> Параметры -> Среда` и выбрать необходимую тему.

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_3.png?raw=true)
Рис. 3. Заходим в параметры

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_4.png?raw=true)
Рис. 4. Меняем тему

3. Чтобы закоментировать блок кода можно выделить его и нажать ПКМ, а затем выбрать `Закомментировать` или воспользоваться комбинацией клавиш `Ctrl+/`.

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_5.png?raw=true)
Рис. 5. Комментируем блок кода

4. Чтобы открыть файл в проводнике нужно выбрать необходимый файл в панели открытых проектов, нажать ПКМ и выбрать `Показать в проводнике`.

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_6.png?raw=true)
Рис. 6. Открываем файл в проводнике

5. В Qt для файлов-проектов используется расширение `.pro`.

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_7.png?raw=true)
Рис. 7. Файл-проект

6. Чтобы запустить код без отладки можно воспользоваться соответствующими кнопкой снизу слева (1 на рис. 8.) или нажать `Ctrl+R`.

7. Чтобы запустить код в режиме отладки можно воспользоваться соответствующими кнопкой снизу слева (2 на рис. 8.) или нажать `F5`.

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_8.png?raw=true)
Рис. 8. Запуск кода

8. Чтобы установить точку останова можно нажать на пространство рядом с номером строчки кода или установить курсор на нужную строчку и нажать `F9`.

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_9.png?raw=true)
Рис. 9. Установливаем точку останова

9. Содаём программу с заданным кодом, устанавливаем точки останова, запускаем код в режиме отладки.

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_10.png?raw=true)
Рис. 10. Запуск кода, первая остановка

Видим, что int при создании содержит 0, а double мусор.

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_11.png?raw=true)
Рис. 11. Вторая остановка

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_12.png?raw=true)
Рис. 12. Третья остановка

10. Закрываем проект, переходим в `Начало -> Примеры`.
11. Выбираем проект "Calculator Form Example".
12. Изучаем проект.
13. Выбираем комплект сборки.
14. Переходим на вкладку `Редактор` и начинаем сборку.

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_13.png?raw=true)
Рис. 13. Сборка

15. Выбираем "main.cpp" и устанавливаем курсор на слово show.

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_14.png?raw=true)
Рис. 14. Main.cpp

Нажимаем `F1`, открывается справка.

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_15.png?raw=true)
Рис. 15. Открылась справка

16. Выбираем "calculatorform.ui" 

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_16.png?raw=true)
Рис. 16. Calculatorform.ui

17. Мы попали на вкладку `Дизайн`. 

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_17.png?raw=true)
Рис. 17. `Дизайн` "calculatorform"

Заменяем английский текст (1) и собираем проект (2).

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_18.png?raw=true)
Рис. 18. Заменили текст

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab7/Screenshots/Screenshot_19.png?raw=true)
Рис. 19. Запустили проект

#### Вывод: мы изучили основные возможности создания и отладки программ в Qt. Узнали как можно поменять оформление, как найти файлы проекта, научились коментировать, а так же запускать код в режиме отладки и без.