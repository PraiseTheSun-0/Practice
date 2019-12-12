#include "pch.h"
#include <iostream>

struct student
{
	char name[100];
	int group;
	int sec[5] = { 0 };
};

int main()
{
	student stud[10] = { "Krank P.L.",1,{1,2,5,2,0},"Frank L.P.",1,{5,5,5,3,2},"Drank P.D.",2,{4,4,3,2,1},
		"Greg K.R.",2,{0,0,0,4,5},"Bran G.J.",3,{0,0,0,1,2} };
	bool flag = true;
	for (int i = 0; i < 10; i++)
	{
		if (stud[i].sec[0]>0 || stud[i].sec[1]>0 || stud[i].sec[2]>0) {
			std::cout << stud[i].name << ' ' << stud[i].group << std::endl;
			flag = false;
		}
	}
	if(flag)std::cout << "Did not find" << std::endl;
}
