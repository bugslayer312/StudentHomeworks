#include "Header.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
bool Ñonversion_First_name(const Student* Students)
{
	return toupper(Students->First_name[0]) < 'K';
}
bool Ñonversion_Last_name(const Student* Students)
{
	return toupper(Students->Last_name[0]) < 'P';
}
int CountIf(Student** students, int count, StudentCompareFunc compare)
{
	int kol = 0;
	for (int i = 0; i < count; ++i)
		if ((*compare)(students[i]))
			++kol;
	return kol;
}

bool ball_5(const struct Student* students)
{
	return (students->sr_ball) > 5.0;
}

Student* show(Student** students, int count, StudentCompareFunc compare)
{
	for (int i = 0; i < count; ++i)
		if ((*compare)(students[i]))
			return students[i];
}

struct Student* WriteStudent()
{
	struct Student* students = (struct Student*)malloc(sizeof(struct Student));
	std::cout << "Ââåäèòå èìÿ: "; std::cin >> students->First_name;
	std::cout << "Ââåäèòå Ôàìèëèþ: "; std::cin >> students->Last_name;
	std::cout << "Ââåäèòå ñðåäíèé áàë: "; std::cin >> students->sr_ball;
	return students;
}


void BubbleSort(struct Student** Students, int count, CompareTwoStudentsFunc compare)
{
	for (int i = 1; i < count; ++i)
	{
		if ((*compare)(Students[i - 1], Students[i])>0)
		{
			Swap(&Students[i - 1], &Students[i]);
		}
	}
}

int CompareStudentFirstName(const struct Student* students1, const struct Student* students2)
{
	return strcmp(students1->First_name, students2->First_name);
}
int CompareStudentLastName(const struct Student* students1, const struct Student* students2)
{
	return strcmp(students1->Last_name, students2->Last_name);
}
int CompareStudentsr_ball(const struct Student* students1, const struct Student* students2)
{
	if (students1->sr_ball == students2->sr_ball)
	{
		return 0;
	}
	return (students1->sr_ball < students2->sr_ball) ? -1 : 1;
}
void Sort(struct Student** students, int count, CompareTwoStudentsFunc compare)
{
	for (int subCount = count; subCount > 1; --subCount)
	{
		BubbleSort(students, subCount, compare);
	}
}

void Swap(Student** stud1, Student** stud2)
{
	Student* tmp = *stud1;
	*stud1 = *stud2;
	*stud2 = tmp;

}
void PrintAllStudent(Student** student, const int n)
{
	for (int i(0); i < n; i++)
	{
		PrintStudent(student[i]);
	}
}
void PrintStudent(const Student* student)
{
	std::cout << "Èìÿ: " << student->First_name << ", Ôàìèëèÿ: " << student->Last_name << ", ñðåäíèé áàë: " << student->sr_ball << std::endl;
}