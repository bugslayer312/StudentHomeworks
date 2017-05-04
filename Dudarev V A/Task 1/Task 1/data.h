struct Student
{	
	char SurName[20];
	char FirstName[20];
	float average;
};
struct Student* ReadStudent();
void PrintStudent(struct Student* student);

