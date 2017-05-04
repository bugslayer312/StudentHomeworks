#include "data.h"
#include "stdafx.h"
using namespace std;
struct Student* ReadStudent()
{
	struct Student* result = (struct Student*)malloc(sizeof(struct Student));
	cout << "Enter the surname:" << endl;
	cin >> result->SurName;
	cout << "Enter the first name:" << endl;
	cin >> result->FirstName;
	cout << "Enter the average score:" << endl;
	cin >> result->average;
	return result;
}
void PrintStudent(struct Student* student)
{
	std::cout << "Surname: " << student->SurName << ", First name: " << student->FirstName << ", Average score: " << student->average << std::endl;
}
