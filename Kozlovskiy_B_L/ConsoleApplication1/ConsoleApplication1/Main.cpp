#include "Data.h"
#include<cstdlib>
#include<cstring>
#include<ctype.h>
#include <iostream>

int main()
{
	int const count = 5;
	struct Student* array[count];
	for (int i = 0; i < count; ++i)
	{
		array[i] = ReadStudent();
	}
	std::printf("sort by Name\n");
	Sort(array, count, CompareStudentByName);
	PrintAllStudents(array, count);

	std::printf("sort by Lastname\n");
	Sort(array, count, CompareStudentByLastname);
	PrintAllStudents(array, count);

	std::printf("sort by Ball\n");
	Sort(array, count, CompareStudentByBall);
	PrintAllStudents(array, count);

	std::printf("Find ball >8.5\n");
	PrintStudent(Find(array, count, BallGreater_85));

	std::printf("Find Lastname >""P""\n");
	PrintStudent(Find(array, count, LastnameStartsWithLetterLessThan_P));

	std::printf("Find Lastname >""K""\n");
	PrintStudent(Find(array, count, NameStartsWithLetterLessThan_K));

	std::printf("kollichestvo chisel >8.5\n");
	std::printf("%d\n", CountIf(array, count, BallGreater_85));

	std::printf("kolichestvo Lastname >P\n");
	std::printf("%d\n", CountIf(array, count, LastnameStartsWithLetterLessThan_P));

	std::printf("kolichestvo Name>K\n");
	std::printf("%d\n", CountIf(array, count, NameStartsWithLetterLessThan_K));

	for (int i = 0; i < count; ++i)
		free(array[i]);

	system("pause");
	return 0;
}