
#pragma once

#include "Data.h"


struct ListNode
{
	struct Data* ListData;
	struct ListNode* Next;
};

struct ListNode* Create(struct Data* listData);
void DestroyFirst(struct ListNode* node);
void DestroyNewFirst(struct ListNode* node);
struct ListNode* Insert(struct ListNode* first, struct ListNode* newNode);
int GetCount(struct ListNode* first);
void PrintList(struct ListNode* first);
ListNode* RemoveAll(ListNode* first, DataCompareFunc predicate);
ListNode* Revertl(ListNode* first);
ListNode* CreateListCopy(ListNode* node, ListNode* newfirst);
void Swap(ListNode* node1, ListNode* node2);
typedef bool(*TwoDataCompareFunc) (const struct Data*, const struct Data*);
ListNode* BubbleSort(ListNode* first, TwoDataCompareFunc predicate);
