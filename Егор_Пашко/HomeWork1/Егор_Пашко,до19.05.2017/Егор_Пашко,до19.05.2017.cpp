///////////////////////////// 
///����_�����,��19.05.2017///
/////////////////////////////

#include "stdafx.h"
#include "FAIL.h"
#include <iomanip>
#include <iostream>

struct student
{

	char First_name[20];
	char Last_name[20];
	float sr_ball;
};


int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "\t\t\t***�������� ���� �����***\n" << std::endl;
	const int kol_vo_st = 3;  //�������� ���-�� ���������

	student ssilka[kol_vo_st];
	for (int i(0); i <kol_vo_st; i++)
	{

		std::cout << std::endl << i + 1 << ")�������: \n\n";
		Input(&ssilka[i]);
		system("cls");
	}

	std::cout << "�������� ��� ������ �������: 1) ������� ���������� �������� 2) �o��������� ������ |:";
	int kyda;
	std::cin >> kyda;
	if (kyda = 1)
	{
		poisk_kriterii(ssilka, kol_vo_st);
	}
	if (kyda = 2)
	{
		std::cout << "�� ��� ����������� ���������: 1) ������� ���� 2) �� ��������: ";
		int vibor;
		std::cin >> vibor;
		if (vibor = 1)
			sortirovka(ssilka, kol_vo_st);
		if (vibor = 2)
			sort_sortirovka(ssilka, kol_vo_st);
	}



	std::cout << std::endl;
	for (int i(0); i < kol_vo_st; i++)
	{
		std::cout << " " << ssilka[i].First_name << " \t " << ssilka[i].Last_name << "\t" << ssilka[i].sr_ball << "\n";
	}


	system("pause");
	return 0;
}