// HomeWork1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Data.h"
#include "List.h"

#include <iostream>

	bool SalaryGreaterThan500(const struct Data* data)
	{
		return data->Salary >= 500;
	}

	bool SalaryLessThan500(const struct Data* data)
	{
		return data->Salary < 500;
	}
	bool FindSymbol(const struct Data* data)
	{
		return  strchr(data->Name, 77);
	}
	bool ComparNode(const struct Data* data1, const struct Data* data2)
	{
		if (data1->Salary == data2->Salary)
		{
			return -1;
		}
		return data1->Salary < data2->Salary;
	}

	 void TestListFunctional()
	{
	struct ListNode* first = NULL;
	int const count = 5;
	for (int i = 0;i < count; ++i)
	{
	 struct Data* data = ReadData();
	 struct ListNode* node = Create(data);
	 first = Insert(first, node);
	}
	PrintList(first);
	std::cout << std::endl << "FindSymbol 'M' " << std::endl;
	RemoveAll(first, FindSymbol);
	std::cout << std::endl << "SalaryGreaterThan500" << std::endl;
	RemoveAll(first, SalaryGreaterThan500);
	std::cout << std::endl << "SalaryLessThan500" << std::endl;
	RemoveAll(first, SalaryLessThan500);
	std::cout << std::endl << "first" << std::endl;
	PrintList(first);
	std::cout << std::endl << "Revertl(first)" << std::endl;
	Revertl(first);
	std::cout << std::endl << "BubbleSort" << std::endl;
	BubbleSort(first, ComparNode);
	
	system("pause");
	} 
	int main()
	{
		 TestListFunctional();

		return 0;
	}
 
