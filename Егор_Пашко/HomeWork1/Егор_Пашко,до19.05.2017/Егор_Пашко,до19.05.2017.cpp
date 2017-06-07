///////////////////////////// 
///Егор_Пашко,до19.05.2017///
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

	std::cout << ("Сортируем по имени\n");
	Sort(arr, count, CompareStudentFirstName);
	PrintAllStudent(arr, count);

	std::cout << ("Сортируем по фамилии\n");
	Sort(arr, count, CompareStudentLastName);
	PrintAllStudent(arr, count);

	std::cout << ("Сортируем по среднему балу\n");
	Sort(arr, count, CompareStudentsr_ball);
	PrintAllStudent(arr, count);

	std::cout << "Найти студента с балом выше 5.0\n";
	PrintStudent(show(arr, count, ball_5));

	std::cout << "Поиск по критерию Имя <""P""\n";
	PrintStudent(show(arr, count, Сonversion_First_name));

	std::cout << "Поиск по критерию Фамилии <""P""\n";
	PrintStudent(show(arr, count, Сonversion_Last_name));

	std::cout << "Кол-во студентов с баллом выше 5.0: ";
	std::cout << CountIf(arr, count, ball_5);

	std::cout << "\nкол-во имен  < K: ";
	std::cout << CountIf(arr, count, Сonversion_First_name);

	std::cout << "\nКол-во фамилий < P: ";
	std::cout << CountIf(arr, count, Сonversion_Last_name);
	std::cout << std::endl;

	for (int i = 0; i < count; ++i)
		free(arr[i]);
	return 0;
}
