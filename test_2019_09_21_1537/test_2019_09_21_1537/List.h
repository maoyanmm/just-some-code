#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef int DATATYPE;

typedef struct ListNode
{
	DATATYPE _data;
	struct ListNode* _prev;
	struct ListNode* _next;
}ListNode;

typedef struct ListHead
{
	ListNode* _head;
}ListHead;

void ListInit(ListHead* plist);
void ListPushBack(ListHead* plist, DATATYPE x);
void ListPopBack(ListHead* plist);
ListNode* ListCreate(DATATYPE x);
void ListPrint(ListHead* plist);
void ListPushFront(ListHead* plist, DATATYPE x);
void ListPopFront(ListHead* plist);
void ListInsert(ListNode* node, DATATYPE x);