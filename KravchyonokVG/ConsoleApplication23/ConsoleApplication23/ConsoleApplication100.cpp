// ConsoleApplication23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Data.h"
#include "cstring"
#include "ctype.h"

#include <iostream>


int CompareDataByName(const struct Data* data1, const struct Data* data2)
{
	return strcmp(data1->Name, data2->Name);
}

int CompareDataBySalary(const struct Data* data1, const struct Data* data2)
{
	if (data1->Salary == data2->Salary)
	{
		return 0;
	}
	return (data1->Salary < data2->Salary) ? -1 : 1;
}

typedef int(*CompareTwoDataFunc)(const struct Data*, const struct Data*)

void swap(struct Data** data1, struct Data** data2)
{
	struct Data* tmp = *data1;
	*data1 = *data2;
	*data2 = tmp;
}

void BubbleSortIteration(struct Data** data, int count, CompareTwoDataFunc compare)
{
	for (int i = 1; i < count; ++i)
	{
		//if (strcmp(data[i - 1]->Name, data[i]->Name) > 0)
		if ((*compare) (data[i - 1], data[i]) > 0)
		{
			swap(&data[i - 1], &data[i]);
		}
	}
}

void BubbleSort(struct Data** data, int count, CompareTwoDataFunc compare)
{
	for (int subCount = count; subCount > 1; --subCount)
	{
		BubbleSortIteration(data, subCount, compare);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int const count = 5;
	struct Data* array[count];
	for (int i = 0; i < count; ++i)
	{
		array[i] = ReadData();
	}

	BubbleSort(array, count, CompareDataBySalary);

	for (int i = 0; i < count; ++i)
	{
		PrintData(array[i]);
		Free(array[i]);
	}

	

	return 0;
}

