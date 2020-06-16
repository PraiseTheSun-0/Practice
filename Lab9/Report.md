МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 9<br/> по дисциплине "Программирование"
<br/>

студента 1 курса группы ПИ-б-о 191(1)  
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

#### Цель: Познакомиться с Google Test и Google Mock Framework. Изучить базовые понятия относящийся к тестированию кода. Научиться тестировать классы в среде разработки Qt Creator.

После настройки Qt выполняем проверку и запускаем тест по умолчанию 

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab9/Screenshots/Screenshot_1.png?raw=true)

Рис. 1. Результат теста в консоли

Повторяем через `Результаты тестирования`

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab9/Screenshots/Screenshot_2.png?raw=true)

Рис. 2. Результат теста

Пишем [тесты](https://github.com/PraiseTheSun-0/Practice/tree/master/Lab9) и запускаем:

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab9/Screenshots/Screenshot_3.png?raw=true)

Рис. 3. Результаты тестов

Видим ошибку в тесте. Она возникает тут:

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab9/Screenshots/Screenshot_4.png?raw=true)

Рис. 4. Ошибка

Мы ожидаем close(), но метод вызывает open() :

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab9/Screenshots/Screenshot_5.png?raw=true)

Рис. 5. Реализация метода

Нужно в реализации метода open() заменить на close() и тест будет успешно пройден:

![](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab9/Screenshots/Screenshot_6.png?raw=true)

Рис. 6. После исправления

#### Вывод: я познакомился с Google Test и Google Mock Framework, изучил базовые понятия относящийся к тестированию кода, научился тестировать классы в среде разработки Qt Creator.