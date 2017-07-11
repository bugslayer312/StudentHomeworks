
#include "FAIL.h"
#include<cstdlib>

#include <iostream>

void test_student();

int main()
{
	test_student();
	return 0;
}

void test_student() {
	const int count = 2;
	struct Student* arr[count];
	for (int i = 0; i <count; i++) {
		arr[i] = ReadStudent(); 
	}

	std::cout << ("Sort on name\n");
	Sort(arr, count, CompareStudentFirstName);
	PrintAllStudent(arr, count);

	std::cout << ("Sort on last name\n");
	Sort(arr, count, CompareStudentLastName);
	PrintAllStudent(arr, count);

	std::cout << ("Sort on middle ball\n");
	Sort(arr, count, CompareStudentsr_ball);
	PrintAllStudent(arr, count);

	std::cout << "To find the student with a ball higher than> 5.0\n";
	PrintStudent(show(arr, count, high_middle_ball_5));

	std::cout << "Search in criterion Name <""P""\n";
	PrintStudent(show(arr, count, Check_first_name_less_than_P));

	std::cout << "Search in criterion of the Surname<""K""\n";
	PrintStudent(show(arr, count, Check_last_name_less_than_K));

	std::cout << "The number of students with point is higher 5.0: ";
	std::cout << CountIf(arr, count, high_middle_ball_5);

	std::cout << "\nquantity of names < K: ";
	std::cout << CountIf(arr, count, Check_last_name_less_than_K);

	std::cout << "\nquantity of last name < P: ";
	std::cout << CountIf(arr, count, Check_first_name_less_than_P);
	std::cout << std::endl;

	for (int i = 0; i < count; ++i)
		free(arr[i]);
}