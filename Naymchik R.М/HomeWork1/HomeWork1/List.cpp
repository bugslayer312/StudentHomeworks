#include "List.h"
#include <iostream>
#include <cstdlib>

bool selector = true;

struct ListNode* Create(struct Data* listData)
{
	struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
	result->ListData = listData;
	result->Next = NULL;
	return result;
}

void Destroy(struct ListNode* node, bool selector)
{
	while (node)
	{
		struct ListNode* p = node;
		node = node->Next;
		if(selector)
		{
			free(p);
		}
		else
		{
			free(p->ListData);
			free(p);
		}
	}
}
struct ListNode* Insert(struct ListNode* first, struct ListNode* newNode)
{
	newNode->Next = NULL;
	if (!first)
	{
		return newNode;
	}

	struct ListNode* prev = NULL;
	struct ListNode* p = first;
	while (p)
	{
		if (CompareByName(newNode->ListData, p->ListData) < 0)
			// если код элемент в строке newNode->ListData меньше чем  p->ListData то отриц число  
			// по алфавиту newNode->ListData идет ранше чем p->ListData
		{
			if (prev)
			{
				prev->Next = newNode;
				newNode->Next = p;
				return first;
			}
			else
			{
				newNode->Next = p;
				return newNode;
			}
		}
		prev = p;
		p = p->Next;
	}
	prev->Next = newNode;// 
	return first;
}

int GetCount(struct ListNode* first)// считает сколько элементов в списке
{
	int result = 0;
	struct ListNode* p = first;
	while (p)
	{
		++result;
		p = p->Next;
	}
	return result;
}

void PrintList(struct ListNode* first)
{
	struct ListNode* p = first;
	while (p)
	{
		PrintData(p->ListData);
		p = p->Next;
	}
}
ListNode* GreateNewfirst(ListNode* newfirst, ListNode* first)
 {
	struct ListNode* p = first;
	struct ListNode* newp = newfirst;
	while (p->Next)
	{
		p = p->Next;
		newp->Next = (struct ListNode*)malloc(sizeof(struct ListNode));
		newp = newp->Next;
		newp->ListData = p->ListData;
		newp->Next = NULL;
	}
	return newfirst;
}
ListNode* FreeMemory(ListNode* newfirst ,size_t& counter)
{
	struct ListNode* newp = newfirst;
	struct ListNode* newp1 = newfirst;
	while (newp1->Next)
	{
		if (counter)
		{
			--counter;
			newp1 = newp1->Next;
		}
		else {
			newp1 = newp1->Next;
			newp = newp->Next;
		}
	}
	struct ListNode* pfr = newp->Next;
	newp->Next = NULL;
	while (pfr)
	{
		struct ListNode* pfr2 = pfr;
		pfr = pfr->Next;
		free(pfr2);
	}
	return 0;
}
void Swap(ListNode* node1, ListNode* node2)
{
	char NameTmp[20];
	strncpy(NameTmp, node1->ListData->Name, strlen(node1->ListData->Name) + 1);
	int SalaryTmp = node1->ListData->Salary;
	strncpy(node1->ListData->Name, node2->ListData->Name, strlen(node2->ListData->Name) + 1);
	node1->ListData->Salary = node2->ListData->Salary;
	strncpy(node2->ListData->Name, NameTmp, strlen(NameTmp) + 1);
	node2->ListData->Salary = SalaryTmp;
}

ListNode* RemoveAll(ListNode* first, DataCompareFunc predicate)
{
	struct ListNode* p = first;
	struct ListNode* newfirst = (struct ListNode*)malloc(sizeof(struct ListNode));
	newfirst->ListData = p->ListData;
	newfirst->Next = NULL;
	GreateNewfirst(newfirst, first);
	struct ListNode* newp2 = newfirst;
	struct ListNode* newpfirst2 = newp2->Next;
	size_t counter = 0;
	int	size = GetCount(newfirst);
	for (; newpfirst2->Next;)
	{
		int size1 = size - counter;
		if ((*predicate)(newp2->ListData) && size1 > 1)//проверяем первый элемент
		{
				struct ListNode* newptakt = newp2;
				struct ListNode* newptakt2 = newpfirst2;
				while (newptakt2)
				{
					Swap(newptakt, newptakt2);
					newptakt2 = newptakt2->Next;
					newptakt = newptakt->Next;

				}
				++counter;
				if ((*predicate)(newp2->ListData))
				{
					continue;
				}
				--size;	
		}
		newpfirst2 = newpfirst2->Next;
		newp2 = newp2->Next;
	}
	if ((*predicate)(newfirst->ListData))
	{
		Destroy(newfirst, selector);
		return 0;
	}
	FreeMemory(newfirst, counter);
	PrintList(newfirst);
	Destroy(newfirst, selector);
	return 0;
}
ListNode* Revertl(ListNode* first)
{
	struct ListNode* p = first;
	struct ListNode* newfirst = (struct ListNode*)malloc(sizeof(struct ListNode));
	newfirst->ListData = p->ListData;
	newfirst->Next = NULL;
	GreateNewfirst(newfirst, first);
	struct ListNode* newp2 = newfirst;
	struct ListNode* newp3 = newfirst;
	
	for (size_t takt = 1, counter = GetCount(first), max = (int)(counter / 2); takt <= max; takt++)
	{
		newp3 = newfirst;
		for (size_t max2 = counter - takt; max2; --max2)
		{
			newp3 = newp3->Next;
		}
		Swap(newp2, newp3);
		newp2 = newp2->Next;
	}
	std::cout << std::endl;
	PrintList(newfirst);
	Destroy(newfirst, selector);
	selector = false;
	return NULL;
}
void BubbleSort(ListNode* first, TwoDataCompareFunc predicate)
{
	struct ListNode* p = first;
	for (size_t takt1 = 1, counter = GetCount(first); p; ++takt1)
	{
		struct ListNode* p2 = p;
		for (size_t takt2 = 1, max = counter - takt1; max; --max, ++takt2)
		{
			p2 = p;
			for (size_t max2 = counter - takt2 - takt1; max2; --max2)
			{
				p2 = p2->Next;
			}
			if (!(*predicate)(p2->ListData, p2->Next->ListData))
			{
				Swap(p2, p2->Next);
			}
		}
		p = p->Next;
	}
	std::cout << std::endl;
	PrintList(first);
	Destroy(first, selector);
}
