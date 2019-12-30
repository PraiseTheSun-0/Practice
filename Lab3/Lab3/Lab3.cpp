#include "pch.h"
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
