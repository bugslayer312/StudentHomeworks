// Stroki.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <tchar.h>
#include <string.h>
#include "Header.h"
using namespace std;

const int MAX = 256;

int _tmain(int argc, _TCHAR* argv[])
{
	char stroka[] = "Anyone who reads Old and Middle English literary texts (16th-18th) will be familiar with the mid-brown volumes of the EETS, with the symbol of Alfred's jewel embossed on the front cover.";
	int size_stroka = strlen(stroka);
	char *str_result = new char[size_stroka];
	
	//Задание 1:
	//Написать функцию, которая удаляет из строки символ с заданным номером.
	int nElem;
	printf("%s\n", stroka);
	printf("Vvedite nomer simvola, kotoriy nuzhno udalit':  ");
	scanf("%d", &nElem);
	if (nElem < size_stroka + 1)
		printf("%s\n", DeleteOneChar(str_result, stroka, nElem));
	else
		printf("Error\n");
	printf("\n");
		
	//Задание 2:
	//Написать функцию, которая удаляет из строки все вхождения в нее заданного символа.
	int sym = -1;
	printf("\nVvedite symvol, kotoriy nuzhno udalit':  ");
	getchar();
	sym = getchar();
	printf("%s\n", DeleteChar(str_result, stroka, sym));
	printf("\n");
	
	//Задание 3:
	//Написать функцию, которая вставляет в строку в указанную позицию заданный символ.
	int nPoz;
	printf("\nVvedite symvol, kotoriy nuzhno vstavit':  ");
	getchar();
	sym = getchar();
	printf("Vvedite nomer pozicii, kuda nuzhno vstavit' simvol '%c' :  ", sym);
	scanf("%d", &nPoz);
	if (nPoz < strlen(str_result) + 1)
		printf("%s\n", InsertChar(str_result, nPoz, sym));
	else
		printf("Error\n");
	printf("\n");
	
	//Задание 4:
	//Написать программу, которая заменяет все символы точки "." в строке, введенной
	//пользователем, на символы восклицательного знака "!".
	char string[] = "Hello. I'm glad to see you. Let's go to...";
	printf("%s\n", string);
	char *p = string;
	while (strchr(p, '.') != NULL)
	{
		p = strchr(p, '.');
		*p = '!';
	}
	printf("%s\n", string);
	printf("\n");

	//Задание 5:
	//Пользователь вводит строку символов и искомый символ, посчитать сколько раз он встречается
	//в строке.
	char str_5[MAX];
	int count = 0;
	p = str_5;
	printf("Vvedite stroky: \n");
	scanf("%s", &str_5);
	printf("Vvedite symvol is etoy stroki:  \n");
	getchar();
	sym = getchar();
	for (; *p != '\0'; ++p)
	{
		if (*p == (char)sym)
			++count;
	}
	printf("Simvol %c vstrechaetsya %d raz\n", sym, count);
	printf("\n");
	system("pause");

	//Задание 6:
	//Пользователь вводит строку.Определить количество букв, количество цифр и количество
	//остальных символов, присутствующих в строке. Достаточно сравнить код символа с диапазоном
	//кодов цифр. Код символа 0 – 48, 1 – 49, 2 – 50 …. 9 – 57.
	size_t count_num = 0;
	size_t count_let = 0;
	size_t count_sym = 0;
	printf("%s\n", stroka);
	for (p = stroka; *p != '\0'; ++p)
	{
		if (47 < (int)*p && (int)*p < 58)
		{
			++count_num;
			continue;
		}
		if (64 < (int)*p && (int)*p < 91 || 96 < (int)*p && (int)*p < 123)
		{
			++count_let;
			continue;
		}
		if (31 < (int)*p && (int)*p < 48 || 57 < (int)*p && (int)*p < 65 || 90 < (int)*p && (int)*p < 97 || 122 < (int)*p && (int)*p < 127)
		++count_sym;
	}
	printf("Kolichestvo cifr v stroke: %d\n", count_num);
	printf("Kolichestvo bukv v stroke: %d\n", count_let);
	printf("Kolichestvo symvolov v stroke: %d\n", count_sym);
	printf("\n");

	//Задание 7:
	//Дана строка символов.Заменить в ней все пробелы на табуляции.
	for (p = string; *p != '\0'; ++p)
	{
		if (*p == ' ')
			*p = '\t';
	}
	printf("%s\n", string);
	printf("\n");

	//Задание 9:
	//Подсчитать количество слов во введенном предложении.
	printf("%s\n", stroka);
	p = stroka;
	if (strlen(stroka) > 1)
		count = 1;
	else
		count = 0;
	for (; *p != '\0'; ++p)
	{
		if (*p == ' ')
			count++;
	}
	printf("Kolichestvo slov v stroke:  %d\n", count);
	printf("\n");

	//Задание 10:
	//Дана строка символов.Необходимо проверить является ли эта строка палиндромом.
	char str_10[] = "Some men interpret nine memos";
	Polindrom(str_10);
	Polindrom(string);
	
	
	delete[] str_result;
	system("pause");
	return 0;
}

