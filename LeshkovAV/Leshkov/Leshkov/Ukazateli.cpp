// Leshkov.cpp: ���������� ����� ����� ��� ����������� ����������.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "List.h"
using namespace std;

const int BegDiapA = 0;		// ������ � ��������� � ��������� � ����� ��������
const int BegDiapB = 0;	// ������ � ��������� � ��������� � ����� ��������
const int WidthDiap = 20;	// ������ ��������� ��������� �����
const int L = 20;

int _tmain(int argc, _TCHAR* argv[])
{
	//���� ��� �������: �[M] � B[N] (M � N �������� � ����������). 
	int M, N;
	printf("Vvedite razmer massiva A [0 - 15]: \t");
	scanf("\n%d", &M);
	printf("Vvedite razmer massiva B [0 - 15]: \t");
	scanf("\n%d", &N);
	int *pmass_A = new int[M];
	int *pmass_B = new int[N];
	
	printf("\nZadanie 1\n");
	GenerateMassiv(pmass_A, M, BegDiapA, WidthDiap);
	PrintMassiv(pmass_A, M);
	GenerateMassiv(pmass_B, N, BegDiapB, WidthDiap);
	PrintMassiv(pmass_B, N);

	//1. ���������� ������� ������ ������ ���������� ���������� �������, 
	//� ������� ����� ������� �������� ������� A,
	//������� �� ���������� � ������ B, ��� ����������.
	
	int *pmass_C = new int[M];
	int nElem = UnionMassiv(pmass_A, pmass_B, pmass_C, M, N);
	nElem = NotRepeatElement(pmass_C, nElem);
	PrintMassiv(pmass_C, nElem);
	delete[] pmass_C;
	
	//2. ���������� ������� ������
	//������ ���������� ���������� �������, � ������� ����� ������� �������� �������� A � B,
	//������� �� �������� ������ ��� ���, ��� ����������.

	int *pmass_D = new int[M + N];
	int *pmass_E = new int[N];
	nElem = UnionMassiv(pmass_A, pmass_B, pmass_D, M, N);
	int nElem_2 = UnionMassiv(pmass_B, pmass_A, pmass_E, N, M);
	for (size_t i = 0; i < nElem_2; i++)
		*(pmass_D + nElem + i) = *(pmass_E + i);
	nElem += nElem_2;
	printf("\nZadanie 2\n");
	nElem = NotRepeatElement(pmass_D, nElem);
	PrintMassiv(pmass_D, nElem);
	delete[] pmass_E;

	//3. ���������� ������� ������ ������ ���������� ���������� �������,
	//� ������� ����� ������� �������� ����� ��������.
		
	for (size_t i = 0, j = 0; i < M, j < N; i++, j++) {
		*(pmass_D + i) = *(pmass_A + i);
		*(pmass_D + M + j) = *(pmass_B + j);
	}
	printf("\nZadanie 3\n");
	PrintMassiv(pmass_D, M + N);
	
	//4. ���������� ������� ������ ������ ���������� ���������� �������,
	//� ������� ����� ������� ����� �������� ���� �������� ��� ����������.
	nElem = 0;
	int *pmass_F = new int[M];
	int *ptrF = pmass_F;
	for (size_t i = 0; i < M; i++){
		for (size_t j = 0; j < N; j++){
			if (*(pmass_A + i) == *(pmass_B + j)){
				*ptrF++ = *(pmass_A + i);
				nElem++;
			}
		}

	}
	nElem = NotRepeatElement(pmass_F, nElem);
	printf("\nZadanie 4\n");
	PrintMassiv(pmass_F, nElem);
	
	delete[] pmass_D;
	delete[] pmass_F;

	//5. ��� ������ : �[M](M �������� � ����������).���������� ������� �� �������
	//������ ��� �������� ��������.������������ ������ ������ � ������,
	//� ����� � ������� ���� ������, ��� ����� �������.

	printf("\nZadanie 5\n");
	printf("Vvedite razmer massiva A: \t");
	scanf("\n%d", &M);
	int *pA = new int[M];
	int *pA_end = pA + M - 1;
	size_t vybor = 0;
	nElem = 0;
	GenerateMassiv(pA, M, BegDiapA, WidthDiap);
	PrintMassiv(pA, M);
	printf("Kakie elementy massiva udalit: \n'1' - nechetnye\n'2' - chetnye\n");
	scanf("\n%d", &vybor);
	switch (vybor)
	{
	case 1:
		for (int i = 0; i < M; i++) {
			if (*(pA + i) % 2) {
				*(pA + i) = *pA_end;
				i--;
				M--;
				pA_end--;
			}
		}
				break;
	case 2:
		for (int i = 0; i < M; i++) {
			if (!(*(pA + i) % 2)) {
				*(pA + i) = *pA_end;
				i--;
				M--;
				pA_end--;
			}
		}
				break;

	default:
		printf("Uncorrect value!!!\n");
		break;
	}
	PrintMassiv(pA, M);

	delete[] pA;

	//6. �������� �������, ������� �������� ��������� �� ������������ ������ � ��� ������.
	//������� ������ ������� �� ������� ��� ������� ����� � ������� ���������
	//�� ����� ������������ ������.

	printf("\nZadanie 6\n");
	PrintMassiv(pmass_B, N);
	int *p_mass_new = MassivNotPrime(pmass_B, N);
	PrintMassiv(p_mass_new, N);
	delete[] pmass_A;
	delete[] pmass_B;
	delete[] p_mass_new;

	//7. �������� �������, ������� �������� ��������� �� ����������� ������ � ��� ������.
	//������� ������������ �������������, ������������� � ������� ��������
	//� ��������� ������������ �������
	
	printf("\nZadanie 7\n");
	int static_mass[L];
	int *ptr_mass = static_mass;
	GenerateMassiv(static_mass, L, -5, 10);
	PrintMassiv(static_mass, L);
	int **sort_mass = SortMassiv(ptr_mass, L);
	int *mass_null = *(sort_mass + 0);
	int *mass_neg = *(sort_mass + 1);
	int *mass_pos = *(sort_mass + 2);
	int *mass_nElem = *(sort_mass + 3);
	PrintMassiv(mass_null, *mass_nElem);
	PrintMassiv(mass_neg, *(mass_nElem + 1));
	PrintMassiv(mass_pos, *(mass_nElem + 2));

	
	delete[] mass_null;
	delete[] mass_neg;
	delete[] mass_pos;
	delete[] mass_nElem;
	delete[] sort_mass;
	system("pause");
	return 0;
}