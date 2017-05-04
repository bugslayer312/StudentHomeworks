#include "stdafx.h"
#include "data.h"
using namespace std;
typedef int(*TwoStudentsCompareFunc)(const struct Student*, const struct Student*);
void CompareStudent(const struct Student* student_a, const struct Student* student_b, TwoStudentsCompareFunc compare){
	int compareResult = compare(student_a, student_b);
	if (compareResult){
		if (compareResult < 0){
			printf("%s is less than %s\n", student_a->SurName, student_b->SurName);
		}
		else{
			printf("%s is greater than %s\n", student_a->SurName, student_b->SurName);
		}
	}
	else{
		printf("%s equals to %s\n", student_a->SurName, student_b->SurName);
	}
}
int CompareFunc(const struct Student* student_a, const struct Student* student_b){
	int criterion;
	cout << "By what criterion (0 - a surname, 1 - a name, 2 - GPA): ";
	cin >> criterion;
	if (criterion == 0) {
		return strcmp(student_a->SurName, student_b->SurName);
	}
	else if (criterion == 1) {
		return strcmp(student_a->FirstName, student_b->FirstName);
	}
	else {
		if (student_a->average > student_b->average) {
			return 1;
		}
		else if(student_a->average == student_b->average){
			return 0;
		}
		else {
			return -1;
		}
	}
}
typedef bool(*OneStudentsCompareFunc)(const struct Student*);
void PrintByCondition(const struct Student* student_a, OneStudentsCompareFunc predicate){
		if ((*predicate)(student_a)){
			cout << "The average score student 1 is more than 5";
		}
		else {
			cout << "The average score student 1 is less than 5";
		}
}
bool CompareOneStudentByAverage(const struct Student* student){
	return student->average > 5;
}
void swap(struct Student** student_a, struct Student** student_b){
	struct Student* tmp = *student_a;
	*student_a = *student_b;
	*student_b = tmp;
}
void Sort(Student** student, int count, TwoStudentsCompareFunc compare) {
	int compareResult;
	int i = 0;
	compareResult = compare(student[i], student[i + 1]);
	if (compareResult == 1) {
		swap(student[i], student[i + 1]);
	}
	for (int i = 0; i < count; ++i) {
		PrintStudent(student[i]);
	}
}
int CompareFuncSurName(const struct Student* student_a, const struct Student* student_b) {
	return strcmp(student_a->SurName, student_b->SurName);
}
Student* Find(Student** student, int count, OneStudentsCompareFunc compare) {
	for (int i = 0; i < count; ++i) {
		if ((*compare)(student[i])) {
			cout << "The first element meeting criterion of search: " << endl << student[i]->SurName << endl << student[i]->FirstName << endl << student[i]->average << endl;
			return student[i];
		}
	}
}
int CountIf(Student** student, int count, OneStudentsCompareFunc compare) {
	int count_if = 0;
	for (int i = 0; i < count; ++i) {
		if ((*compare)(student[i])) {
			count_if++;
		}
	}
	cout << "Quantity of the elements meeting criterion of search: " << count_if;
	return count_if;
}
int main(int argc, _TCHAR* argv[]){
	setlocale(LC_ALL, "RUS");
	int const count = 2;
	struct Student* array[count];
	for (int i = 0; i < count; ++i){
		array[i] = ReadStudent();
	}
	for (int i = 0; i < count; ++i){
		cout << i << ") ";
		PrintStudent(array[i]);
	}
	struct Student* student_a = ReadStudent();
	struct Student* student_b = ReadStudent();
	int criterion;
	CompareStudent(student_a, student_b, CompareFunc);
	cout << endl;
	PrintByCondition(student_a, CompareOneStudentByAverage);
	cout << endl;
	Sort(array, count, CompareFuncSurName);
	cout << endl;
	Find(array, count, CompareOneStudentByAverage);
	cout << endl;
	CountIf(array, count, CompareOneStudentByAverage);
	cout << endl;
	system("pause");
	return 0;
}