#include "Data.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

struct Student* CreateStudent(char const* name, char const* lastName, float ball)
{
	struct Student* students = (struct Student*)malloc(sizeof(struct Student));
	strncpy(students->Name, name, 20);
	strncpy(students->lastName, lastName, 20);
	students->ball = ball;
	return students;
}
struct Student* ReadStudent()
{
	struct Student* students = (struct Student*)malloc(sizeof(struct Student));
	std::cout << "Enter name, lastname and ball" << std::endl;
	std::cin >> students->Name >> students->lastName >> students->ball;
	return students;
}
void PrintStudent(struct Student* students)
{
	std::cout << "Name: " << students->Name << ", Lastname: " << students->lastName << ", Ball: " << students->ball << std::endl;
}
int CompareStudentByName(const struct Student* students1, const struct Student* students2)
{
	return strcmp(students1->Name, students2->Name);
}
int CompareStudentByLastname(const struct Student* students1, const struct Student* students2)
{
	return strcmp(students1->lastName, students2->lastName);
}
int CompareStudentByBall(const struct Student* students1, const struct Student* students2)
{
	if (students1->ball == students2->ball)
	{
		return 0;
	}
	return (students1->ball < students2->ball) ? -1 : 1;
}
bool NameStartsWithLetterLessThan_K(const struct Student* Students)
{
	return toupper(Students->Name[0]) < 'K';
}
bool LastnameStartsWithLetterLessThan_P(const struct Student* Students)
{
	return toupper(Students->Name[0]) < 'P';
}
bool BallGreater_85(const struct Student* Students)
{
	return (Students->ball) > 8.5;
}
Student* Find(Student** students, int count, StudentCompareFunc compare)
{
	for (int i = 0; i < count; ++i)
		if ((*compare)(students[i]))
			return students[i];
}
void swap(struct Student** data1, struct Student** data2)
{
	struct Student* tmp = *data1;
	*data1 = *data2;
	*data2 = tmp;
}
void BubbleSortIteration(struct Student** Students, int count, CompareTwoStudentsFunc compare)
{
	for (int i = 1; i < count; ++i)
	{
		if ((*compare)(Students[i - 1], Students[i])>0)
		{
			swap(&Students[i - 1], &Students[i]);
		}
	}
}
void PrintByConditition(struct Student** array, int count, StudentCompareFunc predicate)
{
	for (int i = 0; i < count; ++i)
	{
		if ((*predicate)(array[i]))
		{
			PrintStudent(array[i]);
		}
	}
}
void Sort(struct Student** students, int count, CompareTwoStudentsFunc compare)
{
	for (int subCount = count; subCount > 1; --subCount)
	{
		BubbleSortIteration(students, subCount, compare);
	}
}
int CountIf(Student** students, int count, StudentCompareFunc compare)
{
	int kol = 0;
	for (int i = 0; i < count; ++i)
		if ((*compare)(students[i]))
			++kol;
	return kol;
}
void PrintAllStudents(Student**students, int count)
{
	for (int i = 0; i < count; ++i)
		PrintStudent(students[i]);
}