#pragma once

struct Student {

	char First_name[20];
	char Last_name[20];
	float sr_ball;
};

typedef int(*CompareTwoStudentsFunc)(const struct Student*, const struct Student*);
typedef bool(*StudentCompareFunc)(const struct Student*);
struct Student* ReadStudent();
void BubbleSort(struct Student** Students, int count, CompareTwoStudentsFunc compare);
int CompareStudentFirstName(const struct Student* students1, const struct Student* students2);
int CompareStudentLastName(const struct Student* students1, const struct Student* students2);
int CompareStudentsr_ball(const struct Student* students1, const struct Student* students2);
void Sort(struct Student** students, int count, CompareTwoStudentsFunc compare);
bool high_middle_ball_5(const struct Student* students);
Student* show(Student** students, int count, StudentCompareFunc compare);
void Swap(Student** stud1, Student** stud2);
void PrintAllStudent(Student** student, const int n);
int CountIf(Student** students, int count, StudentCompareFunc compare);
void PrintStudent(const Student* student);
bool Check_last_name_less_than_K(const struct Student* Students);
bool Check_first_name_less_than_P(const Student* Students);