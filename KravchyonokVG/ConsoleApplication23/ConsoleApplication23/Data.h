#pragma once

struct Student
{
	char Name[20];
	char Surname[20];
	float Evaluation;
};

typedef bool(*StudentCompareFunc)(const struct Student*);
struct Student* CreateStudent(char const* name, char const* surname, float evaluation);
struct Student* ReadStudent();
void PrintStudent(struct Student* student);
int CompareBySurnameName(const struct Student* s1, const struct Student* s2);


