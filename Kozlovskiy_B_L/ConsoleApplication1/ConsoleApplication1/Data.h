#pragma once

struct Student
{
	char Name[20];
	char lastName[20];
	float ball;
};

typedef bool(*StudentCompareFunc)(const struct Student*);
typedef int(*CompareTwoStudentsFunc)(const struct Student*, const struct Student*);
struct Student* CreateStudent(char const* name, int ball);
struct Student* ReadStudent();
void PrintStudent(struct Student* students);
int CompareStudentByName(const struct Student* students1, const struct Student* students2);
int CompareStudentByLastname(const struct Student* students1, const struct Student* students2);
int CompareStudentByBall(const struct Student* students1, const struct Student* students2);
bool BallGreater_85(const struct Student* Students);
bool LastnameStartsWithLetterLessThan_P(const struct Student* Students);
bool NameStartsWithLetterLessThan_K(const struct Student* Students);
Student* Find(Student** students, int count, StudentCompareFunc compare);
void PrintByConditition(struct Student** array, int count, StudentCompareFunc predicate);
void Sort(struct Student** students, int count, CompareTwoStudentsFunc compare);
int CountIf(Student** students, int count, StudentCompareFunc compare);
void PrintAllStudents(Student**students, int count);