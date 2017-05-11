
#pragma once

#include "Data.h"


struct ListNode
{
	struct Data* ListData;
	struct ListNode* Next;
};

struct ListNode* Create(struct Data* listData);
void Destroy(struct ListNode* node, bool selector);
struct ListNode* Insert(struct ListNode* first, struct ListNode* newNode);
int GetCount(struct ListNode* first);
void PrintList(struct ListNode* first);
ListNode* FreeMemory(ListNode* newfirst, size_t& counter);
ListNode* RemoveAll(ListNode* first, DataCompareFunc predicate);
ListNode* Revertl(ListNode* first);
ListNode* GreateNewfirst(ListNode* newfirst, ListNode* first);
void Swap(ListNode* node1, ListNode* node2);
typedef bool(*TwoDataCompareFunc) (const struct Data*, const struct Data*);
void BubbleSort(ListNode* first, TwoDataCompareFunc predicate);
