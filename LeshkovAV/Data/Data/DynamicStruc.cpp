// Data.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Data.h"
#include "List.h"
#include <cstdlib>
#include <iostream>

bool SalaryGreaterThan500(const struct Data* data)
{
	return data->Salary >= 500;
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct ListNode* first = NULL;
	int const count = 5;
	for (int i = 0; i < count; ++i)
	{
		struct Data* data = ReadData();
		struct ListNode* node = Create(data);
		first = Insert(first, node);
	}
	PrintList(first);
	struct ListNode* first2 = NULL;
	while (struct ListNode* found = Find(first, SalaryGreaterThan500))
	{
		first = Remove(first, found);
		first2 = PushBack(first2, found);
	}
	std::cout << "\nFirst list: " << GetCount(first) << " elements" << std::endl;
	PrintList(first);
	std::cout << "\nSecond list: " << GetCount(first2) << " elements" << std::endl;
	PrintList(first2);
	Destroy(first);
	Destroy(first2);
	
	
	/*struct Data *arr[3];
	for (int i = 0; i < 3; ++i)
	{
		arr[i] = ReadData();
	}
	for (int i = 0; i < 3; ++i)
	{
		PrintData(arr[i]);
		free(arr[i]);
	}*/

	system("pause");
	return 0;
}
