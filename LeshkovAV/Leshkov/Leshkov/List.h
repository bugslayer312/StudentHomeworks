#pragma once
#include "stdafx.h"

void GenerateMassiv(int *ptr, size_t size, int begin, int width);
void PrintMassiv(int *ptr, size_t size);
int UnionMassiv(int *ptrA, int *ptrB, int *ptrC, size_t sizeA, size_t sizeB);
int NotRepeatElement(int *ptr, size_t size);
int *MassivNotPrime(int *ptr, int &size);
int **SortMassiv(int *ptr, int size);