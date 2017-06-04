// HomeWork1.cpp: определяет точку входа для консольного приложения.
// Тема: Многомерные динамические массивы.
// Сергёй Зуёнок, гр.Б42016

#include "stdafx.h"
using namespace std;

const size_t cName = 15, cNumb = 7;
size_t M = 6, N = 7;

void arrPrn(int **mass, size_t _x, size_t _y);
void arrInit(int **mass, size_t _x, size_t _y);
int delCol(int **mass, size_t _x, size_t &_y, size_t _z);
int addCol(int **mass, size_t _x, size_t &_y, size_t _z);
int moveRowCol(int **mass, size_t _x, size_t _y, int stepRow, int stepCol);
int **transp(int **mass, int M, int N);

void phonebook(void);
void(*options[]) (int &exitcode, char **masP[], char **pName,
	char **pNumber, size_t &nSize, size_t &nRec);
int menu(void);
void set_rand(char **[], size_t, size_t);
void out(char **[], size_t);
void get_number(char(&name)[cName], char(&number)[cNumb]);

void read(int &, char **masP[], char **, char **, size_t &, size_t &),
enter(int &, char **masP[], char **, char **, size_t &, size_t &),
del(int &, char **masP[], char **, char **, size_t &, size_t &),
edit(int &, char **masP[], char **, char **, size_t &, size_t &),
fname(int &, char **masP[], char **, char **, size_t &, size_t &),
fnumb(int &, char **masP[], char **, char **, size_t &, size_t &),
quit(int &, char **masP[], char **, char **, size_t &, size_t &);

int main() {
	/*int **mass = new int*[M];
	for (int **ptr = mass, **end = mass + M; ptr != end; ptr++) *ptr = new int[N];
	arrInit(mass, M, N);
	arrPrn(mass, M, N);
	size_t _z = 1;*/

	//****Task 1:
	/*cout << "Which column you want to delete?\nEnter the column number... ";
	cin >> _z;
	delCol(mass, M, N, _z);
	arrPrn(mass, M, N);*/

	//****Task 2:
	/*cout << "In which position do you want to add a column?\nEnter the column number... ";
	cin >> _z;
	addCol(mass, M, N, _z);
	arrPrn(mass, M, N);*/

	//****Task 3:
	/*for (int dirc = 1, i = 0; i < M; i++, dirc *= -1) {
		for (size_t j = 0; j < N; j++) {
			moveRowCol(mass, M, N, dirc, dirc);
			arrPrn(mass, M, N);
		}
	}*/

	//****Task 4:
	//arrPrn(transp(mass, M, N), N, M);

	//****Task 1:
	phonebook();

	/*for (int **ptr = mass, **end = mass + M; ptr < end; ptr++) delete[] * ptr;
	delete[] mass;*/

	//system("pause");
	return 0;
}

void arrPrn(int **mass, size_t _x, size_t _y) {
	for (int **ptr = mass, **end = mass + _x; ptr != end; ptr++) {
		for (int *ptr_y = *ptr, *end = *ptr + _y; ptr_y != end; ptr_y++) {
			printf("%4d", *ptr_y);
		}
		printf("\n");
	}
	printf("\n");
}

void arrInit(int **mass, size_t _x, size_t _y) {
	int i = 1;
	for (int **ptr = mass, **end = mass + _x; ptr != end; ptr++)
		for (int *ptr_y = *ptr, *end = *ptr + _y; ptr_y != end; ptr_y++)
			*ptr_y = i++;
}

int delCol(int **mass, size_t _x, size_t &_y, size_t nDelCol) {
	if (!(nDelCol > 0 && nDelCol <= _y)) {
		printf("The column number values are out of range\n"
			"Deletion is canceled.\n\n");
		return 1;
	}
	else {
		printf("Delete column number %d\n\n", nDelCol);
		_y--;
		for (size_t i = 0; i < _x; i++) {
			int *temp = new int[_y];
			for (size_t j = 0, k = 0; j < _y + 1; j++)
				if (j != nDelCol - 1)
					temp[k++] = mass[i][j];
			delete[] mass[i];
			mass[i] = temp;
		}
		return 0;
	}
}

int addCol(int **mass, size_t _x, size_t &_y, size_t nAddCol) {
	if (!(nAddCol > 0 && nAddCol <= _y + 1)) {
		printf("The column number values are out of range\n"
			"Addition to this position is not possible.\n\n");
		return 1;
	}
	else {
		printf("Add column number %d\n\n", nAddCol);
		nAddCol--;
		_y++;
		char *ptr = new char[_y * sizeof(**mass)];
		for (size_t i = 0; i < _x; i++) {
			int *temp = new int[_y];
			for (int **ptr_x = mass, **end = mass + i + 1; ptr_x != end; ptr_x++) {
				memcpy(temp, *ptr_x, nAddCol * sizeof(**ptr_x));
				memcpy(temp + nAddCol + 1, *ptr_x + nAddCol,
					(_y - nAddCol - 1) * sizeof(**ptr_x));
			}
			delete[] mass[i];
			mass[i] = temp;
			mass[i][nAddCol] = 0;
		}
		delete[] ptr;
		return 0;
	}
}

int moveRowCol(int **mass, size_t _x, size_t _y, int stepRow, int stepCol) {
	if (stepRow < 0) {
		moveRowCol(mass, _x, _y, _x + stepRow, 0);
		return 0;
	} {
		char *ptr = new char[stepRow * sizeof(*mass)];
		memcpy(ptr, mass, stepRow * sizeof(*mass));
		memcpy(mass, mass + stepRow, (_x - stepRow) * sizeof(*mass));
		memcpy(mass + _x - stepRow, ptr, stepRow * sizeof(*mass));
		delete[] ptr;
	}
	if (stepCol < 0) {
		moveRowCol(mass, _x, _y, 0, _y + stepCol);
		return 0;
	} {
		char *ptr = new char[stepCol * sizeof(**mass)];
		for (int **ptr_x = mass, **end = mass + _x; ptr_x != end; ptr_x++) {
			memcpy(ptr, *ptr_x, stepCol * sizeof(**ptr_x));
			memcpy(*ptr_x, *ptr_x + stepCol, (_y - stepCol) * sizeof(**ptr_x));
			memcpy(*ptr_x + _y - stepCol, ptr, stepCol * sizeof(**ptr_x));
		}
		delete[] ptr;
	}
	return 0;
}

int **transp(int **mass, int M, int N) {
	int **newMass = new int *[N];
	if (newMass == NULL) {
		cout << "This matrix has no determinant\n";
		exit(1);
	}
	for (int i = 0; i < N; i++) {
		newMass[i] = new int[M];
		if (newMass[i] == NULL) {
			cout << "This matrix has no determinant\n";
			exit(1);
		}
	}
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			newMass[j][i] = mass[i][j];
	return newMass;
}

void phonebook(void) {
	size_t nRec = 10;
	size_t nSize = nRec;

	char **pName = new char*[nRec];
	char **pNumb = new char*[nRec];

	for (size_t i = 0; i < nRec; i++) {
		pName[i] = new char[nSize];
		pNumb[i] = new char[nSize];
	}

	char **masP[] = { pName, pNumb };

	set_rand(masP, nSize, nRec);
	out(masP, nRec);

	int exitcode = 1;
	for (; exitcode;) {
		(*options[menu()])(exitcode, masP, pName, pNumb, nSize, nRec);
	}

	for (char **ptr = pName, **end = pName + sizeof(pName); ptr < end; ptr++) delete[] * ptr;
	delete[] pName;
	for (char **ptr = pNumb, **end = pNumb + sizeof(pNumb); ptr < end; ptr++) delete[] * ptr;
	delete[] pNumb;
}

void get_number(char(&name)[cName], char(&number)[cNumb]) {
	int radix = 10;
	cout << "\nEnter name : ";
	cin >> name;
	cout << name << endl;
	cout << "Enter telephone number : ";
	int t;
	cin >> t;
	_itoa_s(t, number, cNumb, radix);
}

void set_rand(char **p[], size_t nSize, size_t nRec) {
	const char buff = 15;
	int radix = 10;
	char tmp[buff];
	char *xName[buff] = { "Ivanov","Petrov",
		"Sidorov","Zaitcev","Vasilev","Kuzmin",
		"Stepanov", "Novak","Gruzdev","Lesnov" };
	for (size_t j = 0, i = 0; i < nRec; i++) {
		for (j = 0; xName[i][j]; j++) {
			p[0][i][j] = xName[i][j];
		}
		p[0][i][j] = '\0';
		_itoa_s(((rand() % 1000000) * 123 + 1000000), tmp, nSize, radix);
		for (j = 0; j < strlen(tmp); j++) {
			p[1][i][j] = tmp[j];
		}
		p[1][i][j] = '\0';
	}
}

void out(char **p[], size_t nRec) {
	cout << "Total " << nRec << " records." << endl;
	cout << "Name:\tTel number:\n";
	for (size_t i = 0; i < nRec; i++) {
		cout.width(10);
		cout << p[0][i] << "   ";
		cout.width(7);
		cout << p[1][i] << endl;
	}
}

int find(char **p[], const size_t nRec) {
	/*char *nam = *p[0];
	char *numb = *p[1];
	char name, number;
	get_number(name, number);
	for (int i = 0; i < nRec; i++)
		if (*(nam + i) == name)
			if (*(numb + i) == number)
				return i;*/
	return -1;
}
//
//void get_number(char& name, char& number) {
//	cout << "Введите код города : ";
//	cin >> name;
//	cout << "Введите номер телефона : ";
//	cin >> number;
//	cout << "\numb";
//}

void(*options[]) (int &exitcode, char **masP[], char **pName,
	char **pNumber, size_t &nSize, size_t &nRec) = {
	read,
	enter,
	del,
	edit,
	fname,
	fnumb,
	quit
};

int menu(void) {
	printf("\n\n******************\n");
	char ch = 1;
	do {
		printf("1. Read\n");
		printf("2. Enter\n");
		printf("3. Delete\n");
		printf("4. Edit\n");
		printf("5. Find by name\n");
		printf("6. Find by number\n");
		printf("7. Quit\n\n");
		printf("Select a number: ");
		ch = _getch();
		printf("\n\n");
	} while (!strchr("1234567", ch));
	return ch - 49;
}

void read(int &exitcode, char **masP[], char **pName,
	char **pNumber, size_t &nSize, size_t &nRec) {
	printf("In read.\n");
	out(masP, nRec);
}

void enter(int &exitcode, char **masP[], char **pName,
	char **pNumber, size_t &nSize, size_t &nRec) {
	printf("In enter.\n\n");
	//char *nam = *masP[0];
	//char *numb = *masP[1];
	char **name_add = new char*[++nRec];
	char **number_add = new char*[nRec];
	char name[cName], number[cNumb];
	get_number(name, number);
	for (size_t i = 0; i < nRec; i++) {
		if (i == nRec - 1) {
			*(name_add + i) = name;
			*(number_add + i) = number;
		}
		else {
			*(name_add + i) = *(masP[0] + i);
			*(number_add + i) = *(masP[1] + i);
		}
	}

	for (char **ptr = pName, **end = pName + nRec; ptr < end; ptr++)
		delete[] * ptr;

	for (char **ptr = pName, **end = pName + nRec; ptr < end; ptr++) {
		//*ptr = *name_add++;
		cout << *ptr << endl;
	}

	/*for (char **ptr = pNumber, **end = pNumber + sizeof(pNumber)+1; ptr < end; ptr++)
		delete[] * ptr;*/

		/*masP[0] = name_add;
		masP[1] = number_add;
		out(masP, nRec);*/

		//
		//for (char **ptr = pNumber, **end = pNumber + sizeof(pNumber); ptr < end; ptr++)
		//	delete[] * ptr;
		//delete[] pNumber;

	system("pause");
}

void del(int &exitcode, char **masP[], char **pName,
	char **pNumber, size_t &nSize, size_t &nRec) {
	printf("In del.");
}

void edit(int &exitcode, char **masP[], char **pName,
	char **pNumber, size_t &nSize, size_t &nRec) {
	printf("In edit.");
}

void fname(int &exitcode, char **masP[], char **pName,
	char **pNumber, size_t &nSize, size_t &nRec) {
	printf("Find by name.");
}

void fnumb(int &exitcode, char **masP[], char **pName,
	char **pNumber, size_t &nSize, size_t &nRec) {
	printf("Find by number.");
}

void quit(int &exitcode, char **masP[], char **pName,
	char **pNumber, size_t &nSize, size_t &nRec) {
	printf("In quit.\n\n");
	exitcode = 0;
}