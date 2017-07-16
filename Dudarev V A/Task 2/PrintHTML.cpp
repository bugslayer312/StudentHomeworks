#include "stdafx.h"

typedef unsigned char flag;

void PrintHtml(char const* string, int style) {
	flag bold = 1;
	flag italic = 1;
	flag underline = 1;
	bool bold_1 = false;
	bool italic_1 = false;
	bool underline_1 = false;
	if (style & bold) {
		bold_1 = true;
		std::cout << "<B>";
	}
	style >>= 1;
	if (style & italic) {
		italic_1 = true;
		std::cout << "<I>";
	}
	style >>= 1;
	if (style & underline) {
		underline_1 = true;
		std::cout << "<U>";
	}
	std::cout << string;
	if (underline_1) {
		std::cout << "</U>";
	}
	if (italic_1) {
		std::cout << "</I>";
	}
	if (bold_1) {
		std::cout << "</B>";
	}
}

int choose_style() {
	flag style = 0;
	bool value = false;
	std::cout << "Bold(0 - false, 1 - true): ";
	std::cin >> value;
	if (value) {
		style |= 1;
		value = false;
	}
	std::cout << "\nItalic(0 - false, 1 - true): ";
	std::cin >> value;
	if (value) {
		style |= 0x02;
		value = false;
	}
	std::cout << "\nUnderline(0 - false, 1 - true): ";
	std::cin >> value;
	if (value) {
		style |= 0x04;
	}
	return style;
}

int main(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "RUS");
	char* some_string = (char*)malloc(256);
	std::cout << "Enter the string: ";
	std::cin >> some_string;
	flag style = choose_style();

	PrintHtml(some_string, style);	
	return 0;
}
