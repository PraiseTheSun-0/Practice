МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 1<br/> по дисциплине "Программирование"
<br/>

студента 1 курса группы 191(1)  
Балабанова Никиты Петровича
направления подготовки 09.03.04  
"Программная инженерия"  
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
 - **Овладеть практическими навыками разработки и программирования вычислительного процесса циклической структуры;**
 - **Сформировать навыков программирования алгоритмов разветвляющейся структуры;**
 - **Изучить операторы ветвления. Особенности использования полной и сокращенной формы оператора if и тернарного оператора.**

#### Ход рыботы

Напишем программу для выполенения поставленной задачи

    bool isEqual(double a, double b) {
        double e = 0.00000001;
        return (abs(a - b) < e);
    }

    int main() {
        setlocale(LC_ALL, "Russian");
        double a, b, x1, x2, dx, y, x;
        cout << "Введите a, b, начало промежутка, конец промежутка, dx" << endl;
        cin >> a >> b >> x1 >> x2 >> dx;
        if (!dx) {
            cout << "Шаг не может быть нулём" << endl;
            return 0;
        }
        if (x1 > x2 && dx > 0 || x2 > x1 && dx < 0) {
            cout << "С выбранным шагом нельзя прийти из начала в конец" << endl;
            return 0;
        }
        for (x = x1; x < x2 || isEqual(x, x2); x += dx) {	
            if (x >= x1 && x < a || isEqual(x, a)) {
                y = exp(x) / (3.0 + sin(x));
            }
            else if (x > a && x < b) {
                y = log(x) + x * x;
            }
            else {
                y = 1.0 + sin(-x);
            }
            cout << "При х = " << x << ", y = " << y << endl;
        }
    }

Запустим программу с значениями `a = 0.7`, `b = 1.2`, `x1 = 0.5`, `x1 = 1.5`, `dx = 0.05`

![](https://raw.githubusercontent.com/PraiseTheSun-0/Practice/master/Lab2/Screenshots/Screenshot_01.png "Рис. 1. Ввод данных")

![](https://raw.githubusercontent.com/PraiseTheSun-0/Practice/master/Lab2/Screenshots/Screenshot_02.png "Рис. 2. Результат")

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