#include "Data.h"

#include <cstdlib>
#include <cstring>
#include <iostream>

struct Student* CreateStudent(char const* name, char const* surname, float evaluation)
{
	struct Student* result = (struct Student*)malloc(sizeof(struct Student));
	strncpy(result->Name, name, 20);
	strncpy(result->Name, surname, 20);
	result->Evaluation = evaluation;
	return result;
}

struct Student* ReadStudent()
{
	struct Student* result = (struct Student*)malloc(sizeof(struct Student));
	std::cout << "Enter name, surname and evaluation(0 - 10.0):" << std::endl;
	std::cin >> result->Name >> result->Surname >> result->Evaluation;
	return result;
}

void PrintStudent(struct Student* student)
{
	std::cout << "Name: " << student->Name << ", Surname: " << student->Surname << ", Evaluation: " << student->Evaluation << std::endl;
}

int CompareBySurname(const struct Student* s1, const struct Student* s2)
{
	return strcmp(s1->Surname, s2->Surname);
}
