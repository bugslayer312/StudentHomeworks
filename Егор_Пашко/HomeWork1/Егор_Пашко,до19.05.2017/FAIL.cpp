#include "FAIL.h"

#include <cstdlib>
#include <cstring>
#include <iostream>

struct student
{

	char First_name[20];
	char Last_name[20];
	float sr_ball;
};

void Input(student *s)								//Вводим наших студентов
{

	std::cout << "Введите фамилию студента: ";
	
	std::cin.getline(s->Last_name, 20);


	std::cout << "Введите имя студента: ";
	
	std::cin.getline(s->First_name, 20);

	std::cout << "Введите средний балл студента(1-10): ";
	(std::cin >> s->sr_ball).ignore();
	if (s->sr_ball<0 || s->sr_ball > 10) {
		std::cout << "Попробуйте еще раз" << std::endl;
		Input(s);
	}

	
	std::cout << std::endl;
}
void sortirovka(student s[], int n)					//Сортировка по Баллу
{
	std::cout << " Имя\tФамилия\tСреднии бал" << std::endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (s[i].sr_ball > s[j].sr_ball)
			{
				student temp = s[i];
				s[i] = s[j];
				s[j] = temp;

			}

		}

	}

}

void sort_sortirovka(student s[], int n)			//Сортировка по Алфавиту
{
	std::cout << " Имя\tФамилия\tСреднии бал" << std::endl;
	for (int i = 0, j = i + 1; i < n; i++)
	{
		student temp;
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(s[j].First_name, s[j].First_name) > 0)
			{
				if (strcmp(s[j].Last_name, s[j].Last_name) > 0)
				{
					temp = s[i];
					s[i] = s[j];
					s[j] = temp;
				}
			}
		}
	}
}

int poisk_kriterii(student s[], int n)				//Поиск отдельного студента по критерию 
{
	std::cout << "Выберите студента по критерию: 1) Имя или фамилия 2) Средний бал: ";
	int krit;
	std::cin >> krit;
	if (krit = 1)
	{
		char poisk[15];
		std::cout << "Введите Имя или фамилию студента: ";
		std::cin >> poisk;
		for (int i = 0; i < n; i++)
		{
			if ((strcmp(s[i].First_name, poisk) == 0 || (strcmp(s[i].Last_name, poisk) == 0)))
			{
				std::cout << "Ваш студент найден: ";
				std::cout << s[i].First_name << " " << s[i].Last_name << " " << s[i].sr_ball << "\n";
				system("pause");
				return 0;

			}
		}
		std::cout << "Студент не найден";
		return 0;
	}
	if (krit = 2)
	{
		float poisk;
		std::cout << "Введите средний бал студента: ";
		std::cin >> poisk;
		for (int i = 0; i < n; i++)
		{
			if (s[i].sr_ball = poisk)
			{
				std::cout << "Ваш студент найден: ";
				std::cout << s[i].First_name << " " << s[i].Last_name << " " << s[i].sr_ball << "\n";
				system("pause");
				return 0;

			}
		}
		std::cout << "Студент не найден";
		return 0;
	}

}
