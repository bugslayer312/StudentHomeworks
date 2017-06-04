// Structures_start.cpp: определяет точку входа для консольного приложения.
// Тема: Структуры.
// Сергёй Зуёнок, гр.Б42016

#include "stdafx.h"

struct Student {
	char firstName[20];
	char lastName[20];
	float avrgMark;
};

typedef int(*TwoStudentsCompareFunc) (const struct Student*, const struct Student*);
typedef bool(*StudentCompareFunc) (const struct Student*);

struct Student* inputData(int n);
void PrintForm(Student**students, int count);

void PrintStudent(struct Student* students);

void FreeMem(Student* arr[], int length);

int CmpStdsFName(const struct Student* studentOne, const struct Student* studentTwo);
int CmpStdsLName(const struct Student* studentOne, const struct Student* studentTwo);
int CmpStdsAvrMark(const struct Student* studentOne, const struct Student* studentTwo);

void StdsTwoCmp(Student**students);
void CmpStds(Student**students);

bool CmpFName(const struct Student* student);
bool CmpLName(const struct Student* student);
bool CmpEvltn(const struct Student* student);

void Sort(struct Student** students, int count, TwoStudentsCompareFunc compare);
Student* Find(Student** students, int count, StudentCompareFunc compare);
int Countif(Student** students, int count, StudentCompareFunc compare);

int main() {
	int const count = 3;
	struct Student *students[count];
	for (int i = 0; i < count; i++)	*(students + i) = inputData(i);

	PrintForm(students, count);
	StdsTwoCmp(students);
	CmpStds(students);

	std::cout << "Sort by First Name:\n";
	Sort(students, count, CmpStdsFName);
	PrintForm(students, count);

	std::cout << "Sort by Last Name:\n";
	Sort(students, count, CmpStdsLName);
	PrintForm(students, count);

	std::cout << "Sort by average mark:\n";
	Sort(students, count, CmpStdsAvrMark);
	PrintForm(students, count);

	std::printf("Search for an average mark of more than 6:\n");
	PrintStudent(Find(students, count, CmpEvltn));

	std::cout << "Quantity of First Names (starting with \"I\"): ";
	std::cout << Countif(students, count, CmpFName) << std::endl;
	std::cout << "and of Last Names (starting with \"I\"): ";
	std::cout << Countif(students, count, CmpLName) << std::endl;
	std::cout << "Quantity of students with average mark more then 6.0: ";
	std::cout << Countif(students, count, CmpEvltn) << std::endl;

	FreeMem(students, count);
	return 0;
}

struct Student* inputData(int count) {
	struct Student *group = (struct Student*) malloc(sizeof(struct Student));
	std::cout << "Student\'s First Name (code " << count << "): ";
	std::cin >> group->firstName;
	std::cout << "Student\'s Last Name (code " << count << "): ";
	std::cin >> group->lastName;
	std::cout << "Student\'s average mark (code " << count << "): ";
	while (group->avrgMark < 0 || group->avrgMark > 10) {
		std::cin >> group->avrgMark;
	}
	return group;
}

void PrintStudent(struct Student* students) {
	std::cout << "First Name: " << students->firstName << ", Last Name: "
		<< students->lastName << "; average mark: " << students->avrgMark << "\n";
}

void PrintForm(Student**students, int count) {
	for (int i = 0; i < count; i++)
		std::cout << "First Name: " << students[i]->firstName << ", Last Name: "
		<< students[i]->lastName << "; average mark: " << students[i]->avrgMark << "\n";
}

void FreeMem(Student* arr[], int length) {
	for (int i = 0; i < length; i++) delete *(arr + i);
}

int CmpStdsFName(const struct Student* studentOne, const struct Student* studentTwo) {
	return strcmp(studentOne->firstName, studentTwo->firstName);
}
int CmpStdsLName(const struct Student* studentOne, const struct Student* studentTwo) {
	return strcmp(studentOne->lastName, studentTwo->lastName);
}
int CmpStdsAvrMark(const struct Student* studentOne, const struct Student* studentTwo) {
	if (studentOne->avrgMark == studentTwo->avrgMark) return 0;
	else if (studentOne->avrgMark > studentTwo->avrgMark) return 1;
	else return -1;
}
void StdsTwoCmp(Student**students) {
	int one, two, is_select = 0;
	std::cout << "Enter comparison criterion:" <<
		" 1 - First Name, 2 - Last Name, 3 - Average mark, 4 - Quit\n\n";
	while (is_select > 4 || is_select < 1) std::cin >> is_select;
	if (is_select == 4) return;
	std::cout << "Enter student codes for comparison:\n";
	std::cin >> one >> two;
	if (is_select == 1)	std::cout << CmpStdsFName(students[one], students[two]) << std::endl;
	if (is_select == 2) std::cout << CmpStdsLName(students[one], students[two]) << std::endl;
	if (is_select == 3) std::cout << CmpStdsAvrMark(students[one], students[two]) << std::endl;
}

void CmpStds(Student**students) {
	int numb, refer = 0;
	std::cout.setf(std::ios::boolalpha);
	std::cout << "The evaluation criteria for comparison:\n" <<
		" 1 - First Name, 2 - Last Name, 3 - Average mark, 4 - Quit\n";
	while (refer > 4 || refer < 1) std::cin >> refer;
	if (refer == 4) return;
	std::cout << " Student\'s code ?\n";
	std::cin >> numb;
	if (refer == 1) std::cout << CmpFName(students[numb]) << std::endl;
	if (refer == 2) std::cout << CmpLName(students[numb]) << std::endl;
	if (refer == 3) std::cout << CmpEvltn(students[numb]) << std::endl;
	std::cout.unsetf(std::ios::boolalpha);
}

bool CmpFName(const struct Student* student) {
	return (student->firstName[0] == 'I');
}

bool CmpLName(const struct Student* student) {
	return (student->lastName[0] == 'I');
}

bool CmpEvltn(const struct Student* student) {
	return (student->avrgMark >= 6.0);
}

void Sort(struct Student** students, int count, TwoStudentsCompareFunc compare) {
	struct Student *temp;
	for (int j = 1; j < count; ++j) {
		for (int i = 0; i < count - j; ++i) {
			if (compare(*(students + i), *(students + i + 1))) {
				temp = *(students + i);
				*(students + i) = *(students + i + 1);
				*(students + i + 1) = temp;
			}
		}
	}
}

Student* Find(Student** students, int count, StudentCompareFunc compare) {
	for (int i = 0; i < count; i++)
		if ((*compare)(*(students + i)))
			return *(students + i);
	std::cout << "Search this criterion no results...\n" <<
		"The default result is returned.\n";
	return *students;
}

int Countif(Student** students, int count, StudentCompareFunc compare) {
	int result = 0;
	for (int i = 0; i < count; ++i) {
		if (compare(*(students + i))) {
			result++;
		}
	}
	return result;
}