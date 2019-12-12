#include "pch.h"
#include <iostream>

size_t mystrlen(const char* string)
{
	int length=0;
	int i=0;
	while (string[i]!='\0')
	{
		length++;
		i++;
	}
	return length;
}

int mystrcmp(const char* string1, const char* string2)
{
	int i = -1;
	while (string1[i] != '\0' && string2[i] != '\0')
	{
		i++;
		if (string1[i] > string2[i])return 1;
		if (string1[i] < string2[i])return -1;
	}
	return 0;
}

char* mystrstr(char* string1, const char* string2)
{
	for(int i = 0;i<mystrlen(string1);i++)
	{
		int l = 0;
		if (string1[i] == string2[l])
		{
			int counter = 1;
			l++;

			while ((string1[i+l] == string2[l]) && (l < mystrlen(string2))) {
				counter++;
				l++;
			}
			if (counter == mystrlen(string2)) {
				return &string1[i];
			}
		}
	}
	return nullptr;
}

char* mystrcat(char* destptr, const char* srcptr)
{
	int len = mystrlen(destptr);
	for (int i = 0; i < mystrlen(srcptr); i++)
		destptr[len + i] = srcptr[i];
	destptr[len + mystrlen(srcptr)] = '\0';
	return destptr;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char first[101];
	char second[51];
	std::cin.getline(first,102);
	std::cin.getline(second, 52);
	
	std::cout<<mystrlen(first)<<std::endl;
	
	if (mystrcmp(first, second) > 0) std::cout << "Строка 1 больше строки 2" << std::endl;
	else if (mystrcmp(first, second) < 0) std::cout << "Строка 2 больше строки 1" << std::endl;
	else std::cout << "Строки равны" << std::endl;

	int i = 0;
	if (mystrstr(first, second)) while (&first[i] != mystrstr(first, second)) i++;
	else i = -1;
	std::cout << i << std::endl;

	std::cout << mystrcat(first, second);
}
