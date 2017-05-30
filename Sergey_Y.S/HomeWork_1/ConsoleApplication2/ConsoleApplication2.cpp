
#include "stdafx.h"
#include<cstdlib>
#include<cstring>
#include<ctype.h>
#include <iostream>

struct Student
{
	char name[20];
	char last_name[20];
	float average_mark;
};

typedef int(*CompareTwoStudentsFunc)(const struct Student*, const struct Student*);
typedef bool(*StudentCompareFunc) (const struct Student*);

struct Student* inputData(int n);
void FreeMemory(Student* g[], int n);
void PrintGroup(Student**group, int count);
int CompareStudentsByName(const struct Student* student1, const struct Student* student2);
int CompareStudentsBylast_name(const struct Student* student1, const struct Student* student2);
int CompareStudentsByaverage_mark(const struct Student* student1, const struct Student* student2);
void StudentsTwoCompareFunc(Student**group);
void FuncCompareStudent(Student**group);
bool StudentCompareName(const struct Student* student);
bool StudentCompareLname(const struct Student* student);
bool StudentCompareAscore(const struct Student* student);

void Sort(struct Student** students, int n, CompareTwoStudentsFunc compare);
int CountIf(Student** students, int n, StudentCompareFunc compare);

int main()
{
	int const n = 3;
	struct Student *group[n];

	for (int i = 0; i < n; ++i) {
		group[i] = inputData(i);
	}
	PrintGroup(group, n);
	StudentsTwoCompareFunc(group);
	FuncCompareStudent(group);
	
	std::cout << "Sort by name" << std::endl;
	Sort(group, n, CompareStudentsByName);
	PrintGroup(group, n);
	std::cout << "Sort by last name" << std::endl;
	Sort(group, n, CompareStudentsBylast_name);
	PrintGroup(group, n);
	std::cout << "Sort by average mark" << std::endl;
	Sort(group, n, CompareStudentsByaverage_mark);
	PrintGroup(group, n);

	std::cout << "Quantity of names (more \"c\") " << std::endl;
	std::cout << CountIf(group, n, StudentCompareName) << std::endl;
	std::cout << "Quantity of last names (more \"c\") " << std::endl;
	std::cout << CountIf(group, n, StudentCompareLname) << std::endl;
	std::cout << "Quantity of students (average mark > 8.0) " << std::endl;
	std::cout << CountIf(group, n, StudentCompareAscore) << std::endl;

	FreeMemory(group, n);
	system("pause");
	return 0;
}

struct Student* inputData(int n)
{
	struct Student *group = (struct Student*) malloc(sizeof(struct Student));
	std::cout << "Student\'s name (number " << n << "): ";
	std::cin >> group -> name;
	std::cout << "Student\'s last name (number " << n << "): ";
	std::cin >> group -> last_name;
	std::cout << "Student\'s average mark (number " << n << "): ";
	while (group -> average_mark < 0 || group -> average_mark > 10) {
		std::cin >> group -> average_mark;
	}
	return group;
}
void FreeMemory(Student* g[], int n)
{
	for (int i = 0; i < n; ++i) {
		delete g[i];
	}
}

void PrintGroup(Student**group, int count)
{
	for (int i = 0; i < count; ++i)
		std::cout << "Name " << group[i] -> name << " last_name " << group[i] -> last_name << " average_mark " << group[i] -> average_mark << std::endl;
}

int CompareStudentsByName(const struct Student* student1, const struct Student* student2)
{
	return strcmp(student1 -> name, student2 -> name);
}
int CompareStudentsBylast_name(const struct Student* student1, const struct Student* student2)
{
	return strcmp(student1 -> last_name, student2 -> last_name);
}
int CompareStudentsByaverage_mark(const struct Student* student1, const struct Student* student2)
{
	if (student1 -> average_mark == student2 -> average_mark) {
		return 0;
	}
	if (student1 -> average_mark > student2 -> average_mark) {
		return 1;
	}
	if (student1 -> average_mark < student2 -> average_mark) {
		return -1;
	}
}
void StudentsTwoCompareFunc(Student**group)
{
	int x1, x2, benchmark = 0;

	std::cout << "Benchmark: 1 - Name, 2 - Last name, 3 - Average mark, 4 - Quit" << std::endl;
	while (benchmark > 4 || benchmark < 1) {
		std::cin >> benchmark;
	}
	if (benchmark == 4) return;
	std::cout << " Student\'s number 1 and Student\'s number 2 ?" << std::endl;
	std::cin >> x1 >> x2;
	if (benchmark == 1)	std::cout << CompareStudentsByName(group[x1], group[x2]) << std::endl;
	if (benchmark == 2) std::cout << CompareStudentsBylast_name(group[x1], group[x2]) << std::endl;
	if (benchmark == 3) std::cout << CompareStudentsByaverage_mark(group[x1], group[x2]) << std::endl;
}


void FuncCompareStudent(Student**group)
{
	int x, benchmark = 0;
	std::cout << "Benchmark: 1 - Name, 2 - Last name, 3 - Average mark, 4 - Quit" << std::endl;
	while (benchmark > 4 || benchmark < 1) {
		std::cin >> benchmark;
	}
	if (benchmark == 4) return;
	std::cout << " Student\'s number ?" << std::endl;
	std::cin >> x;

	if (benchmark == 1) {
		std::cout << std::boolalpha << StudentCompareName(group[x]) << std::endl;
	}
	if (benchmark == 2) {
		std::cout << std::boolalpha << StudentCompareLname(group[x]) << std::endl;
	}
	if (benchmark == 3) {
		std::cout << std::boolalpha << StudentCompareAscore(group[x]) << std::endl;
	}

}
bool StudentCompareName(const struct Student* student)
{
	return (student -> name[0] >= 'c');
}
bool StudentCompareLname(const struct Student* student)
{
	return (student -> last_name[0] >= 'c');
}
bool StudentCompareAscore(const struct Student* student)
{
	return (student -> average_mark >= 8.0);
}


void Sort(struct Student** group, int n, CompareTwoStudentsFunc compare)
{
	struct Student *temp;
	for (int j = 1; j < n; ++j) {
		for (int i = 0; i < n - j; ++i) {
			if (compare(group[i], group[i + 1]) == 1) {
				temp = group[i];
				group[i] = group[i + 1];
				group[i + 1] = temp;
			}
		}
	}
}


int CountIf(Student** group, int n, StudentCompareFunc compare)
{
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (compare(group[i])) {
			count++;
		}
	}
	return count;
}
