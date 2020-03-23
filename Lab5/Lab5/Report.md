МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 5<br/> по дисциплине "Программирование"
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

#### Цель: Научиться работать с текстовыми файлами. Закрепить навыки работы со структурами.

Напишем программу для выполнения поставленной задачи:

```c++
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>

int main()
{
    setlocale(LC_ALL, "Russian");
    struct info {
        int passengerId;
        bool survived;
        int Pclass;
        std::string name;
        char sex;
        double age;
        int sibSp;
        int parCh;
        std::string ticket;
        double fare;
        std::string cabin;
        char embarked;
    }; //структура для записи данных
    std::vector<info> storage; //вектор, где структуры буду хранится

    std::ifstream inf("train.csv");
    if (!inf) {
        std::cerr << "Couldn't read" << std::endl;
        exit(1);
    }

    inf.seekg(80); //смещенние на вторую строку
    int i = 0; //переход по элементам вектора
    while (inf) {
        storage.push_back(info()); //добавляем пустую структуру в вектор
        std::string reading, splitting;
        std::getline(inf, reading, '\r'); //читаем строку

        int length = reading.length(),k = 0; //заменяем запятые-разделители на точку с запятой т.к. может встретиться запятая в данных
        bool change = true;
        while (k < length) {
            if (reading[k] == '\"')change = !change;
            if (change)
                if (reading[k] == ',')
                    reading[k] = ';';
            k++;
        }

        std::stringstream toSplit(reading);
        int where = 0;
        std::getline(toSplit, splitting, ';'); //разбиваем строку на отдельные данные
        while (toSplit) {
            std::stringstream data(splitting); 
            switch (where) { //помещаем соответствующие данные в поля структур
            case 0: data >> storage[i].passengerId;
                break;
            case 1: data >> storage[i].survived;
                break;
            case 2: data >> storage[i].Pclass; 
                break;
            case 3: getline(data, storage[i].name);
                break;
            case 4: data >> storage[i].sex;
                break;
            case 5: data >> storage[i].age;
                break;
            case 6: data >> storage[i].sibSp;
                break;
            case 7: data >> storage[i].parCh;
                break;
            case 8: getline(data, storage[i].ticket);
                break;
            case 9: data >> storage[i].fare;
                break;
            case 10: data >> storage[i].cabin;
                break;
            case 11: data >> storage[i].embarked;
                break;
            }
            where++;
            
            std::getline(toSplit, splitting, ';');
        }
        i++; //переходим к следующей структуре в векторе
    }
    int passengers, survived = 0, survivedFirst = 0, survivedSecond = 0, survivedThird = 0, survivedFemale = 0,
        survivedMale = 0, averageAge_count = 0, averageFemale_count = 0, averageMale_count = 0, embarkedS = 0,
        embarkedQ = 0, embarkedC = 0, underAge = 0, underAgeId[200] = { 0 };
    double averageAge = 0, averageFemale = 0, averageMale = 0;
    passengers = storage.size();
    for (int k = 0; k < passengers; k++) {
        if (storage[k].survived) {
            survived++;
            if (storage[k].Pclass == 1)survivedFirst++;
            if (storage[k].Pclass == 2)survivedSecond++;
            if (storage[k].Pclass == 3)survivedThird++;
            if (storage[k].sex == 'f')survivedFemale++;
            if (storage[k].sex == 'm')survivedMale++;
        }
        if (storage[k].age > 0) {
            averageAge += storage[k].age;
            averageAge_count++;
            if (storage[k].sex == 'f') {
                averageFemale += storage[k].age;
                averageFemale_count++;
            }
            if (storage[k].sex == 'm') {
                averageMale += storage[k].age;
                averageMale_count++;
            }
        }
        if (storage[k].embarked == 'S')embarkedS++;
        if (storage[k].embarked == 'C')embarkedC++;
        if (storage[k].embarked == 'Q')embarkedQ++;
        if (storage[k].age < 18 && storage[k].age > 0) {
            underAgeId[underAge] = storage[k].passengerId;
            underAge++;
        }
    }
    averageAge = (int)averageAge/averageAge_count;
    averageFemale = (int)averageFemale/averageFemale_count;
    averageMale = (int)averageMale/averageMale_count;
    std::string mostState;
    if (embarkedC > embarkedS && embarkedC > embarkedQ) mostState = "Cherbourg";
    else if (embarkedS > embarkedC && embarkedS > embarkedQ) mostState = "Southampton";
    else if (embarkedQ > embarkedS && embarkedQ > embarkedC) mostState = "Queenstown";

    std::ofstream outf("result.txt");
    outf << "Общее число выживших: " << survived << std::endl;
    outf << "Выживших из первого класса: " << survivedFirst << std::endl;
    outf << "Выживших из второго класса: " << survivedSecond << std::endl;
    outf << "Выживших их третьего класса: " << survivedThird << std::endl;
    outf << "Выживших женщин: " << survivedFemale << std::endl;
    outf << "Выживших мужчин: " << survivedMale << std::endl;
    outf << "Средний возраст всех пассажиров: " << averageAge << std::endl;
    outf << "Средний возраст женщин: " << averageFemale << ". Мужчин: " << averageMale << std::endl;
    outf << "Штат, в котором село больше всего пассажиров: " << mostState << std::endl;
    outf << "Список идентификаторов несовершеннолетних пассажиров: " << underAgeId[0];
    underAge = 1;
    while (underAgeId[underAge]) {
        outf << ", " << underAgeId[underAge];
        underAge++;
    }
}
```
В результате у нас получился [файл](https://github.com/PraiseTheSun-0/Practice/blob/master/Lab5/Lab5/result.txt) с нужными данными, а именно:
| Характеристика | Результат |
|---|---|
| Общее число выживших | 342 |
| Выживших из первого класса| 136 |
| Выживших из второго класса | 87 |
| Выживших женщин | 119 |
| Выживших мужчин | 109 |
| Средний возраст всех пассажиров | 29 |
| Средний возраст женщин | 27 |
| Средний возраст мужчин | 30 |
| Штат, в котором село больше всего пассажиров | Southampton |

А так же идентификаторы несовершеннолетних пассажиров: 8, 10, 11, 15, 17, 23, 25, 40, 44, 51, 59, 60, 64, 69, 72, 79, 85, 87, 112, 115, 120, 126, 139, 148, 157, 164, 165, 166, 172, 173, 183, 184, 185, 194, 206, 209, 221, 234, 238, 262, 267, 279, 283, 298, 306, 308, 330, 334, 341, 349, 353, 375, 382, 387, 390, 408, 420, 434, 436, 446, 447, 449, 470, 480, 481, 490, 501, 505, 531, 533, 536, 542, 543, 550, 551, 575, 619, 635, 643, 645, 684, 687, 690, 692, 721, 722, 732, 747, 751, 752, 756, 765, 778, 781, 782, 788, 789, 792, 803, 804, 814, 820, 825, 828, 831, 832, 842, 845, 851, 853, 854, 870, 876.

#### Вывод: я получил навыки работы с файлами, закрепил навыки работы со структурами.