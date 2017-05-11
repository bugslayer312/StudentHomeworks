#include "List.h"
#include <iostream>
#include <cstdlib>

struct ListNode* Create(struct Data* listData)
{
	struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
	result->ListData = listData;
	result->Next = NULL;
	return result;
}

void DestroyFirst(struct ListNode* node)
{
	while (node)
	{
		struct ListNode* p = node;
		node = node->Next;
		free(p->ListData);
		free(p);
	}
}
void DestroyNewFirst(struct ListNode* node)
{
	while (node)
	{
		struct ListNode* p = node;
		node = node->Next;
		free(p);
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
	prev->Next = newNode;
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
ListNode* CreateListCopy( ListNode* node, ListNode* newfirst)
 {
	struct ListNode* newNode = newfirst;
	struct ListNode* addNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	addNode->ListData = node->ListData;
	addNode->Next = NULL;
	if (!newfirst)
	{
		newfirst = addNode;
		return newfirst;
	}
	while (newNode->Next)
	{
		newNode = newNode->Next;
	}
	newNode->Next = addNode;
	return newfirst;
}

void Swap(ListNode* node1, ListNode* node2)
{
	struct Data* tmp = node1->ListData;
	node1->ListData = node2->ListData;
	node2->ListData = tmp;
}

ListNode* RemoveAll(ListNode* newfirst, DataCompareFunc predicate)
{
	struct ListNode* p = newfirst;
	struct ListNode* pnext = p->Next;
	while (pnext)
	{
		if ((*predicate)(newfirst->ListData))
		{
			newfirst = pnext;
			free(p);
			p = newfirst;
			pnext = p->Next;
			continue;
		}

		else if ((*predicate)(pnext->ListData))
		{
			if (pnext->Next)
			{
				p->Next = pnext->Next;
				free(pnext);
				pnext = p->Next;
				continue;
			}
			p->Next = NULL;
			free(pnext);
			return newfirst;
		}
		p = p->Next;
		pnext = pnext->Next;
	}
	return newfirst;
}
ListNode* Revertl(ListNode* first)
{
	struct ListNode* newNode1 = first;
	struct ListNode* newNode2 = first;
	
	for (size_t takt = 1, counter = GetCount(first), max = (int)(counter / 2); takt <= max; takt++)
	{
		newNode2 = first;
		for (size_t max2 = counter - takt; max2; --max2)
		{
			newNode2 = newNode2->Next;
		}
		Swap(newNode1, newNode2);
		newNode1 = newNode1->Next;
	}
	return  first;
}
ListNode* BubbleSort(ListNode* first, TwoDataCompareFunc predicate)
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
	return first;
}
