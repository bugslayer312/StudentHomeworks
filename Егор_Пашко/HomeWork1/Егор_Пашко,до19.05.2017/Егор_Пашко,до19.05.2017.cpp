///////////////////////////// 
///����_�����,��19.05.2017///
/////////////////////////////
#include "Header.h"
#include<cstdlib>
#include<cstring>
#include<ctype.h>
#include <iostream>


int main()
{
	setlocale(LC_ALL, "Russian");

	const int count = 2;
	Student* arr[count];
	for (int i = 0; i <count; i++) { arr[i] = WriteStudent(); }

	std::cout << ("��������� �� �����\n");
	Sort(arr, count, CompareStudentFirstName);
	PrintAllStudent(arr, count);

	std::cout << ("��������� �� �������\n");
	Sort(arr, count, CompareStudentLastName);
	PrintAllStudent(arr, count);

	std::cout << ("��������� �� �������� ����\n");
	Sort(arr, count, CompareStudentsr_ball);
	PrintAllStudent(arr, count);

	std::cout << "����� �������� � ����� ���� 5.0\n";
	PrintStudent(show(arr, count, ball_5));

	std::cout << "����� �� �������� ��� <""P""\n";
	PrintStudent(show(arr, count, �onversion_First_name));

	std::cout << "����� �� �������� ������� <""P""\n";
	PrintStudent(show(arr, count, �onversion_Last_name));

	std::cout << "���-�� ��������� � ������ ���� 5.0: ";
	std::cout << CountIf(arr, count, ball_5);

	std::cout << "\n���-�� ����  < K: ";
	std::cout << CountIf(arr, count, �onversion_First_name);

	std::cout << "\n���-�� ������� < P: ";
	std::cout << CountIf(arr, count, �onversion_Last_name);
	std::cout << std::endl;

	for (int i = 0; i < count; ++i)
		free(arr[i]);
	return 0;
}
