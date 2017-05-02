#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <tchar.h>
#include <string.h>
#include "Header.h"
using namespace std;

char *DeleteOneChar(char *str1, char *str2, size_t numElem)
{
	strncpy(str1, str2, numElem - 1);
	for (size_t i = numElem - 1; *(str2 + i) != '\0'; ++i)
		*(str1 + i) = *(str2 + i + 1);
	return str1;
}

char *DeleteChar(char *str1, char *str2, char sym)
{
	char *p_str1 = str1;
	char *p_str2 = str2;
	for (; *p_str2 != '\0'; ++p_str1, ++p_str2)
	{
		if (*p_str2 != sym)
			*p_str1 = *p_str2;
		else
			*p_str1--;
	}
	*p_str1++ = '\0';
	return str1;
}

char *InsertChar(char *str, int numPoz, char sym)
{
	char tmp = *(str + numPoz - 1);
	char tmp2 = *(str + numPoz);
	char *tmpnext = str + numPoz + 1;
	*(str + numPoz - 1) = sym;
	for (size_t i = numPoz; *(str + i) != '\0'; ++i, ++tmpnext)
	{
		*(str + i) = tmp;
		tmp = tmp2;
		tmp2 = *tmpnext;
	}
	return str;
}

void Polindrom(char *str)
{
	printf("%s\n", str);
	bool polindrm = false;
	size_t size = strlen(str) + 1;
	strupr(str);
	char *ptr_begin = str;
	char *str_mirror = new char[size];
	strcpy(str_mirror, str);
	char *ptr_end = strrev(str_mirror);
	while (*ptr_begin != '\0')
	{
		if (!(isalpha(*ptr_begin)))
		{
			ptr_begin++;
			continue;
		}
		if (!(isalpha(*ptr_end)))
		{
			ptr_end++;
			continue;
		}
		if (*ptr_begin == *ptr_end)
		{
			ptr_begin++;
			ptr_end++;
			polindrm = true;
		}
		else
		{
			polindrm = false;
			break;
		}

	}
	delete[] str_mirror;
	if (polindrm)
		printf("String - polindrom\n");
	else
		printf("String - not polindrom\n");
}