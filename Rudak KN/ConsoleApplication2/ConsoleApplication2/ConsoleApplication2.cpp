
#include "stdafx.h"
#include<cstdlib>
#include<cstring>
#include<ctype.h>
#include <iostream>

struct Student
{
	char name[20];
	char l_name[20];
	float a_score;
};

typedef int (*CompareTwoStudentsFunc)(const struct Student*, const struct Student*);
typedef bool(*StudentCompareFunc) (const struct Student*);

struct Student* inputData(int n);
void FreeMem(Student* g[], int n);
void printGroup(Student**group, int count);
int CompareStudentsByName(const struct Student* student1, const struct Student* student2);
int CompareStudentsByl_name(const struct Student* student1, const struct Student* student2);
int CompareStudentsBya_score(const struct Student* student1, const struct Student* student2);
void StudentsTwoCompareFunc(Student**group);
void FuncCompareStudent(Student**group);
bool StudentCompareName(const struct Student* student);
bool StudentCompareLname(const struct Student* student);
bool StudentCompareAscore(const struct Student* student);

void Sort(struct Student** students, int n, CompareTwoStudentsFunc compare);
int CountIf(Student** students, int n, StudentCompareFunc compare);

int main()
{
	setlocale(LC_ALL, "rus");
	int const n = 5;
	struct Student *group[n];

	for (int i = 0; i < n; i++) {
		group[i] = inputData(i);
	}
	printGroup(group, n);
	StudentsTwoCompareFunc(group);
	FuncCompareStudent(group);
	
	
	std::cout << "���������� �� �����" << std::endl;
	Sort(group, n, CompareStudentsByName);
	printGroup(group, n);
	std::cout << "���������� �� �������" << std::endl;
	Sort(group, n, CompareStudentsByl_name);
	printGroup(group, n);
	std::cout << "���������� �� �������� �����" << std::endl;
	Sort(group, n, CompareStudentsBya_score);
	printGroup(group, n);
	
	std::cout << "���������� ���� ������ \"�\" " << std::endl;
	std::cout<< CountIf (group, n, StudentCompareName) << std::endl;
	std::cout << "���������� ������� ������ \"�\" " << std::endl;
	std::cout << CountIf(group, n, StudentCompareLname) << std::endl;
	std::cout << "���������� �������� �� ������� ������ 8 " << std::endl;
	std::cout << CountIf(group, n, StudentCompareAscore) << std::endl;

	FreeMem(group, n);
	system("pause");
	return 0;
}

struct Student* inputData(int n)
{
	struct Student *group = (struct Student*) malloc(sizeof (struct Student));
	std::cout << "��� �������� ����� " << n << " ";
	std::cin >> group->name;
	std::cout << "������� �������� ����� " << n << " ";
	std::cin >> group->l_name;
	std::cout << "������� ���� �������� ����� " << n << " ";
	while (group->a_score < 0 || group->a_score >10) {
		std::cin >> group->a_score;
	}
	return group;
}
void FreeMem(Student* g[], int n)
{
	for (int i = 0; i < n; i++) {
		delete g[i];
	}
}

void printGroup(Student**group, int count) 
{
	for (int i = 0; i < count; ++i)
		std::cout << "Name " << group[i]->name <<" l_name "<< group[i]->l_name << " a_score " << group[i]->a_score<< std::endl;
}

int CompareStudentsByName(const struct Student* student1, const struct Student* student2)
{
	return strcmp(student1->name, student2->name);
}
int CompareStudentsByl_name(const struct Student* student1, const struct Student* student2)
{
	return strcmp(student1->l_name, student2->l_name);
}
int CompareStudentsBya_score(const struct Student* student1, const struct Student* student2)
{
	if (student1->a_score == student2->a_score){
		return 0;
	}
	if (student1->a_score > student2->a_score) {
		return 1;
	}
	if (student1->a_score < student2->a_score) {
		return -1;
	}
}
void StudentsTwoCompareFunc(Student**group)
{
	int x1, x2, criterion=0;
	
	std::cout << "�������� ������ 1-��� 2-������� 3-������� ���� 4-�����" << std::endl;
	while (criterion > 4 || criterion < 1) {
		std::cin >> criterion;
	}
	if (criterion == 4) return;
	std::cout << " N �������� 1 � N �������� 2 ?" << std::endl;
	std::cin >> x1 >> x2;
	if (criterion == 1)	std::cout << CompareStudentsByName(group[x1], group[x2]) << std::endl;
	if (criterion == 2) std::cout << CompareStudentsByl_name(group[x1], group[x2]) << std::endl;
	if (criterion == 3) std::cout << CompareStudentsBya_score(group[x1], group[x2]) << std::endl;
}


void FuncCompareStudent(Student**group)
{
	int x, criterion=0;
	std::cout << "�������� ������ 1-��� 2-������� 3-������� ���� 4-�����" << std::endl;
	while (criterion > 4 || criterion < 1) {
		std::cin >> criterion;
	}
	if (criterion == 4) return;
	std::cout << " N �������� ?" << std::endl;
	std::cin >> x;
	
	if (criterion == 1) {
		std::cout << std::boolalpha << StudentCompareName(group[x]) << std::endl;
	}
	if (criterion == 2) {
		std::cout << std::boolalpha << StudentCompareLname(group[x]) << std::endl;
	}
	if (criterion == 3) {
		std::cout << std::boolalpha << StudentCompareAscore(group[x]) << std::endl;
	}
		
}
bool StudentCompareName(const struct Student* student)
{
	return (student->name[0] >= 'c');
}
bool StudentCompareLname(const struct Student* student)
{
	return (student->l_name[0] >= 'c');
}
bool StudentCompareAscore(const struct Student* student)
{
	return (student->a_score >= 8.0);
}


void Sort(struct Student** group, int n, CompareTwoStudentsFunc compare)
{
	struct Student *temp;
	for (int j = 1; j < n; j++){
		for (int i = 0; i < n - j; i++){
			if (compare(group[i], group[i + 1]) == 1){
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
	for (int i = 0; i < n; i++) {
		if (compare(group[i])) {
			count++;
		}
	}
	return count;
}
