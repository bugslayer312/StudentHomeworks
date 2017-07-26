#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include "conio.h"
#define _CRT_SECURE_NO_WARNINGS

//Task 1

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
const size_t SIZE = 5;

struct Style {

	unsigned int bold = 1;
	unsigned int italic = 2;
	unsigned int underline = 4;

}stHTML;


void PrintHTML(char const* string, int style)
{   
	char styleHTML[sizeof(stHTML) / sizeof(int) * 2]
		          [SIZE] = { "<U>", "</U>",    // - underline
		                     "<I>", "</I>",    // - italic
		                     "<B>", "</B>"  }; // - bold 
	char stringBefore[SIZE * SIZE] = "", stringAfter[SIZE * SIZE] = "";

	for (size_t i(stHTML.underline), j(0); i; i >>= 1, j += 2)
	{
		if (style & i)
		{
			strcpy(stringBefore, strcat(styleHTML[j], stringBefore));
			strcat(stringAfter, styleHTML[j + 1]);
		}
	}

	printf_s("%s%s%s", stringBefore, string, stringAfter);
}


void testBitwiseTASK1()
{
	const char* string = "Hello, world!";
	PrintHTML(string, stHTML.italic | stHTML.underline | stHTML.bold);
	PrintHTML(string, stHTML.italic | stHTML.underline);
}

//Task 2

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

enum paragraphText
{
	_bold = 0x100,
	_italic = 0x100 << 1,
	_underline = 0x100 << 2,


}prghText;


struct  uint_32
{
	unsigned int fontSize;

	unsigned int _bold = 0x100;
	unsigned int _italic = _bold << 1;
	unsigned int _underline = _italic << 1;

	struct HorAliger
	{
		unsigned int left    = 0x800;
		unsigned int centr   = 0x800 << 1;
		unsigned int right   = 0x800 << 2;
		unsigned int justify = 0x800 << 3;

	} horAlg;


} _uint_32;


void  paragraphText(const unsigned int flags)
{
	char prghText[sizeof(_uint_32) / sizeof(int) - 1]
		         [SIZE * 2] = { "<justify>", // alignment(Stretch in width)
					            "<right>",   // alignment(right)
					            "<centr>",   // alignment(centr)
					            "<left>",    // alignment(left)
					            "<U>",       // underline
					            "<I>",       // italic
					            "<B>" };     // bold  

	for (size_t i(_uint_32.horAlg.justify), j(0);
	    j < (sizeof(_uint_32) / sizeof(int) - 1); i >>= 1, ++j)
	{
		if (flags & i)
		{
			printf_s(" %s  ", prghText[j]);
		}
	}		                        
}


void testBitwiseTASK2()
{
	scanf_s("%u", &_uint_32.fontSize);
    _uint_32.fontSize %= 100;
	paragraphText(_uint_32._underline | _uint_32.fontSize     |
		             _uint_32._italic | _uint_32.horAlg.right |
		             _uint_32._bold  );
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

void main()
{
	testBitwiseTASK1();
	testBitwiseTASK2();

	_getch();
}