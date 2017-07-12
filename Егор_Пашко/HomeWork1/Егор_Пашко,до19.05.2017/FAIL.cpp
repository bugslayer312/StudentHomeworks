#include "FAIL.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
bool Check_last_name_less_than_K(const Student* Students)
{
	return toupper(Students->First_name[0]) < 'K';
}
bool Check_first_name_less_than_P(const Student* Students)
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

bool high_middle_ball_5(const struct Student* students)
{
	return (students->sr_ball) > 5.0;
}

Student* show(Student** students, int count, StudentCompareFunc compare)
{
	for (int i = 0; i < count; ++i)
		if ((*compare)(students[i]))
			return students[i];
	return *(students);
}

struct Student* ReadStudent()
{
	struct Student* students = (struct Student*)malloc(sizeof(struct Student));
	std::cout << "Enter name: "; std::cin >> students->First_name;
	std::cout << "Enter last name: "; std::cin >> students->Last_name;
	std::cout << "Enter middle ball: "; std::cin >> students->sr_ball;
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
void PrintAllStudent(Student** student,const int n)
{
	for (int i(0); i < n; i++)
		PrintStudent(student[i]);
	
}
void PrintStudent(const struct Student* students)
{
	std::cout << "Name: " << students->First_name << ", Lastname: " << students->Last_name << ", Ball: " << students->sr_ball << std::endl;
}