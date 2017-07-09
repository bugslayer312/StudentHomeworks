#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "List.h"

void GenerateMassiv(int *ptr, size_t size, int begin, int width)
{
	for (int i = 0; i < size; i++)
		ptr[i] = rand() % width + begin;
}

void PrintMassiv(int *ptr, size_t size)
{
	for (int i = 0; i < size; i++, ptr++)
		printf("%d\t", *ptr);
	printf("\n\n");
}

int UnionMassiv(int *ptrA, int *ptrB, int *ptrC, size_t sizeA, size_t sizeB)
{
	int numElem = 0;
	int *pA = ptrA, *pB = ptrB;
	for (size_t i = 0; i < sizeA; i++, pA++)
	{
		pB = ptrB;
		for (size_t j = 0; j < sizeB; j++, pB++)
		{
			if (*pA == *pB) break;
			if (j == sizeB - 1)
			{
				*ptrC++ = *pA;
				numElem++;
			}
		}

	}
	return numElem;
}

int NotRepeatElement(int *ptr, size_t size)
{
	int *ptr_end = ptr + size - 1;
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (*(ptr + i) == *(ptr + j))
			{
				*(ptr + j) = *ptr_end;
				j--;
				size--;
				ptr_end--;
			}
	return size;
}

int *MassivNotPrime(int *ptr, int &size)
{
	int *p_mass_new = new int[size];
	int *p_new = p_mass_new;
	int _nElem = 0;
	for (size_t i = 0; i < size; i++) {
		if (*(ptr + i) == 1 || *(ptr + i) == 0) {
			*p_new++ = *(ptr + i);
			_nElem++;
			continue;
		}
		for (size_t j = 2; j < (int)((sqrt(*(ptr + i))) + 1); j++) {
			if (!(*(ptr + i) % j)) {
				*p_new++ = *(ptr + i);
				_nElem++;
				break;
			}
		}
	}
	size = _nElem;
	return p_mass_new;
}

int **SortMassiv(int *ptr, int size)
{
	int size_mass = 4;
	int **p_mass = new int*[size_mass];
	for (int **ptr_d = p_mass; ptr_d < p_mass + size_mass; ptr_d++)
		*ptr_d = new int[size];
	int *mass_null = *(p_mass + 0);
	int *mass_neg = *(p_mass + 1);
	int *mass_pos = *(p_mass + 2);
	int *mass_nElem = *(p_mass + 3);
	for (size_t i = 0; i < size_mass; i++)
		*(mass_nElem + i) = 0;
	for (size_t i = 0; i < size; i++) {
		if (*(ptr + i) > 0) {
			*mass_pos++ = *(ptr + i);
			*(mass_nElem + 2) += 1;
			continue;
		}
		if (*(ptr + i) < 0) {
			*mass_neg++ = *(ptr + i);
			*(mass_nElem + 1) += 1;
			continue;
		}
		*mass_null++ = *(ptr + i);
		*mass_nElem += 1;
	}
	return p_mass;
}