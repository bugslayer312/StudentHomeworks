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
		return  strchr(data->Name, 'M') != NULL;
	}
	bool CompareNodeBySalary(const struct Data* data1, const struct Data* data2)
	{
		return data1->Salary <= data2->Salary;
	}

	void CreateCorrectPrintDestroyListCopy(ListNode* first, DataCompareFunc predicate, ListNode* actNewFirst(ListNode*, DataCompareFunc))
		// chtobi bilo hjnjatno v TestListFunctional() s kakoi fynktiei rabotaem  
	{
		struct ListNode* node = first;
		struct ListNode* newfirst = NULL;
		while (node)
		{
			newfirst = CreateListCopy(node, newfirst);
			node = node->Next;
		}
		newfirst = actNewFirst(newfirst, *predicate);
		PrintList(newfirst);
		DestroyNewFirst(newfirst);
	}

	 void TestListFunctional()
	{
	struct ListNode* first = NULL;
	int const count = 5;
	for (size_t i = 0; i < count; ++i)
	{
	 struct Data* data = ReadData();
	 struct ListNode* node = Create(data);
	 first = Insert(first, node);
	}	
	PrintList(first);

	std::cout << std::endl << "FindSymbol 'M':\n";
	CreateCorrectPrintDestroyListCopy(first, FindSymbol, RemoveAll);

	std::cout << std::endl << "SalaryGreaterThan500:\n";
	CreateCorrectPrintDestroyListCopy(first, SalaryGreaterThan500, RemoveAll);

	std::cout << std::endl << "SalaryLessThan500:\n";
	CreateCorrectPrintDestroyListCopy(first, SalaryLessThan500, RemoveAll);

	std::cout << std::endl << "first:\n";
	PrintList(first);
	std::cout << std::endl << "Revertl(first):\n";
	Revertl(first);
	PrintList(first);

	std::cout << std::endl << "BubbleSort";
	BubbleSort(first, CompareNodeBySalary);
	PrintList(first);
	DestroyFirst(first);

	system("pause");
	} 

	int main()
	{
		 TestListFunctional();

		return 0;
	}
 
