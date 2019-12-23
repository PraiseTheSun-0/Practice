#include "pch.h"
#include <iostream>
#include <vector>

struct student
{
	char name[100];
	int group;
	int sec[5] = { 0 };
};

int main()
{
	student stud[10] = { "Frank P.L.",1,{1,2,5,2,0},"Krank L.P.",1,{5,5,5,3,2},"Drank P.D.",2,{4,4,3,2,1},
		"Greg K.R.",2,{0,0,0,4,5},"Bran G.J.",3,{0,0,0,1,2}, "Rank P.L.",1,{3,3,3,2,0},"Fank L.P.",1,{0,0,1,4,5},"Gank P.D.",2,{1,2,2,3,1},
		"Bragg S.R.",2,{0,0,1,1,2},"Morn S.J.",3,{0,2,0,4,2} };
	bool flag = true;
	std::vector<student> bad;
	for (int i = 0; i < 10; i++)
	{
		if (stud[i].sec[0]>0 || stud[i].sec[1]>0 || stud[i].sec[2]>0) {
			bad.push_back(stud[i]);
			flag = false;
		}
	}
	for(int i = 0; i<bad.size(); i++)
		for(int k = 0; k<bad.size()-i-1;k++)
			if(strcmp(bad[k].name, bad[k+1].name)>0)
			{
				student temp = bad[k];
				bad[k] = bad[k + 1];
				bad[k + 1] = temp;
			}
	
	if (flag)std::cout << "Did not find" << std::endl;
	else for (int i = 0; i < bad.size(); i++)	std::cout << bad[i].name << ' ' << bad[i].group << std::endl;
}