#include "stdafx.h"

enum HorAlign {
	left,
	center,
	right,
	justify
};
void PrintBinary(uint32_t flags)
{
	uint32_t flag = 0x8000;
	while (flag)
	{
		if (flags & flag)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		flag >>= 1;
	}
	printf("\n");
}
uint32_t setSetting(bool bold, bool italic, bool underline, HorAlign align_, int size) {
	uint32_t result = 0;
	if (bold) {
		result |= 1;
	}
	if (italic) {
		result |= 0x02;
	}
	if (underline) {
		result |= 0x04;
	}
	uint32_t align_value = align_ << 3;
	result |= align_value;
	uint32_t size_value = size << 7;
	result |= size_value;
	return result;
}
void printSetting(uint32_t result) {
	if (result & 1) {
		printf("Bold: true.");
	}
	else {
		printf("Bold: false.");
	}
	if (result & 0x02) {
		printf("\nItalic: true.");
	}
	else {
		printf("\nItalic: false.");
	}
	if (result & 0x04) {
		printf("\nUnderline: true.");
	}
	else {
		printf("\nUnderline: false.");
	}
	uint32_t mask = 0x00000008 | 0x000000010 | 0x00000020 | 0x00000040;
	HorAlign align = (HorAlign)((result & mask) >> 3);
	mask = 0x0000ff00;;
	int8_t size = (int8_t)((result & mask) >> 7);
	printf("\nHorAlign: %d\nSize: %d", align, size);
}
void input() {
	std::cout << "Bold(0 - false, 1 - true): ";
	bool bold;
	std::cin >> bold;
	std::cout << "Italic(0 - false, 1 - true): ";
	bool italic;
	std::cin >> italic;
	std::cout << "Underline(0 - false, 1 - true): ";
	bool underline;
	std::cin >> underline;
	int align_;
	std::cout << "Align(0 - left, 1 - center, 2 - right, 3 - justify): ";
	std::cin >> align_;
	int size;
	std::cout << "Size: ";
	std::cin >> size;
	uint32_t result;
	switch (align_) {
	case 0:
		result = setSetting(bold, italic, underline, left, size);
	case 1:
		result = setSetting(bold, italic, underline, right, size);
	case 2:
		result = setSetting(bold, italic, underline, center, size);
	case 3:
		result = setSetting(bold, italic, underline, justify, size);
	}
	std::cout << std::endl;
	PrintBinary(result);
	std::cout << std::endl;
	printSetting(result);
}

int main(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "RUS");
	uint32_t result = setSetting(false, true, true, right, 60);
	printSetting(result);
	std::cout << std::endl;
	input();
	std::cout <<  std::endl;
	return 0;
}

