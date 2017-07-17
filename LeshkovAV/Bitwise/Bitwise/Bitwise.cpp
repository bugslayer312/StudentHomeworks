// Bitwise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <iostream>

typedef unsigned int uint_32;
void PrintHtml(char const* string, int style);
uint_32 ParagraphParameters(char* str);
void ParagraphParameters(uint_32 flag);


int main()
{
	PrintHtml("Hello", 7);
	PrintHtml("Hello, World", 3);

	char str1[] = "<B><I><U><horalign=\"center\"><font size=\"32\">Hello, World<\font size><\horalign><\U><\I><\B>";
	printf("\n\n%s\n", str1);
	printf("Flags of the string: %X\n\n", ParagraphParameters(str1));

	ParagraphParameters(0x1207);
	ParagraphParameters(0x5221);
	ParagraphParameters(0x631F);
	printf("\n");
	ParagraphParameters(ParagraphParameters(str1));

	return 0;
}


void PrintHtml(char const* string, int style)
{
//0001 - Underline, 0010 - Italic, 0100 - Bold
	char *str = new char[128];
	strcpy(str, string);
	printf("%s\n", str);
	if (style & 01)
		strrev(strcat(strrev(strcat(str, "</U>")), ">U<"));
	if (style & 02)
		strrev(strcat(strrev(strcat(str, "</I>")), ">I<"));
	if (style & 04)
		strrev(strcat(strrev(strcat(str, "</B>")), ">B<"));
	printf("%s\n", str);
	delete[] str;

}

uint_32 ParagraphParameters(char* str)
{
//0x0001 - Bold, 0x0002 - Italic, 0x0004 - Underline, HorAlign
//HorAlign: 0x0000 - Left, 0x0010 - Center, 0x0020 - Right, 0x0030 - Justify
//0x0100 - 0x6400 Font size
	uint_32 flag = 0x00;
	char str_int[4] = "";
	if (strstr(str, "<B>"))
		flag = flag | 0x01;
	if (strstr(str, "<I>"))
		flag = flag | 0x02;
	if (strstr(str, "<U>"))
		flag = flag | 0x04;
	if (strstr(str, "horalign=\"center\""))
		flag = flag | 0x10;
	else
		if (strstr(str, "horalign=\"righr\""))
			flag = flag | 0x20;
		else
			if (strstr(str, "horalign=\"justify\""))
				flag = flag | 0x30;
	str = strpbrk(strstr(str, "font size"), "0123456789");
	int fontsize = atoi(strncpy(str_int, str, strspn(str, "0123456789")));
	flag = flag | uint_32((fontsize << 8));
	//printf("%X\n", flag);
	
	return flag;
}

void ParagraphParameters(uint_32 flag)
{
//0x0001 - Bold, 0x0002 - Italic, 0x0004 - Underline, HorAlign
//HorAlign: 0x0000 - Left, 0x0010 - Center, 0x0020 - Right, 0x0030 - Justify
//0x0100 - 0x6400 Font size
	
	printf("\nFlags: %X\n", flag);
	printf("Parameters of the Paragraph: \n");
	if (flag & 0x01)
		printf("Bold\n");
	if (flag & 0x02)
		printf("Italic\n");
	if (flag & 0x04)
		printf("Underline\n");
			
	switch (flag & 0x30)
	{
		case 0x00:
			printf("HorAlign: Left\n");
			break;
		case 0x10:
			printf("HorAlign: Center\n");
			break;
		case 0x20:
			printf("HorAlign: Right\n");
			break;
		case 0x30:
			printf("HorAlign: Justify\n");
	}
	
	printf("Font size: %d\n", (flag >> 8) & 0xFF);
}
