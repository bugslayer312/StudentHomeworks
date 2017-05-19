// ConsoleApplication23.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "Data.h"
#include "cstring"
#include "ctype.h"

#include <iostream>


int CompareStudentBySurname(const struct Student* student1, const struct Student* student2)
{
	return strcmp(student1->Surname, student2->Surname);
}

int CompareStudentByEvaluation(const struct Student* student1, const struct Student* student2)
{
	if (student1->Evaluation == student2->Evaluation)
	{
		return 0;
	}
	return (student1->Evaluation < student2->Evaluation) ? -1 : 1;
}

typedef int(*CompareTwoStudentFunc)(const struct Student*, const struct Student*);

void swap(struct Student** student1, struct Student** student2)
{
	struct Student* tmp = *student1;
	*student1 = *student2;
	*student2 = tmp;
}

void BubbleSortIteration(struct Student** student, int count, CompareTwoStudentFunc compare)
{
	for (int i = 1; i < count; ++i)
	{
		//if (strcmp(data[i - 1]->Name, data[i]->Name) > 0)
		if ((*compare) (student[i - 1], student[i]) > 0)
		{
			swap(&student[i - 1], &student[i]);
		}
	}
}

void BubbleSort(struct Student** student, int count, CompareTwoStudentFunc compare)
{
	for (int subCount = count; subCount > 1; --subCount)
	{
		BubbleSortIteration(student, subCount, compare);
	}
}


typedef bool(*StudentCompareFunc)(const Student*);

void PrintByCondition(Student** array, int count, StudentCompareFunc predicate){
	for (int i = 1; i < count; ++i)
	{
		if ((*predicate)(array[i])) {
			PrintStudent((array[i]));
		}
	}
}




int _tmain(int argc, _TCHAR* argv[])
{
	int const count = 5;
	struct Student* array[count];
	for (int i = 0; i < count; ++i)
	{
		array[i] = ReadStudent();
	}
	BubbleSort(array, count, CompareStudentByEvaluation);
	for (int i = 0; i < count; ++i)
	{
		PrintStudent(array[i]);
		free(array[i]);
	}
	return 0;
}