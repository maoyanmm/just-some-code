#include"List.h"
void ListInit(ListHead* plist)
{
	assert(plist);
	plist->_head = ListCreate(0);
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}

void ListPushBack(ListHead* plist, DATATYPE x)
{
	assert(plist);
	ListNode* node = ListCreate(x);
	node->_next = plist->_head;
	node->_prev = plist->_head->_prev;
    plist->_head->_prev->_next = node;
	plist->_head->_prev = node;
}

ListNode* ListCreate(DATATYPE x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_prev = NULL;
}

void ListPrint(ListHead* plist)
{
	assert(plist);
	ListNode* node = plist->_head->_next;
	while (node != plist->_head)
	{
		printf("%d->", node->_data);
		node = node->_next;
	}
	printf("\n");
}

void ListPopBack(ListHead* plist)
{
	assert(plist);
	if (plist->_head == plist->_head->_prev)
	{
		return;
	}
	ListNode* cur = plist->_head->_prev;
	plist->_head->_prev->_prev->_next = plist->_head;
	plist->_head->_prev = plist->_head->_prev->_prev;
	free(cur);
	cur = NULL;

}

void ListPushFront(ListHead* plist, DATATYPE x)
{
	assert(plist);
	ListNode* node = ListCreate(x);
	node->_next = plist->_head->_next;
	node->_prev = plist->_head;
	plist->_head->_next->_prev = node;
	plist->_head->_next = node;
}

void ListPopFront(ListHead* plist)
{
	assert(plist);
	ListNode* node = plist->_head->_next->_next;
	free(plist->_head->_next);
	plist->_head->_next = NULL;
	plist->_head->_next = node;
	node->_prev = plist->_head;
}

void ListInsert(ListNode* node, DATATYPE x)
{
	assert(node);
	ListNode* new = ListCreate(x);
	new->_next = node;
	new->_prev = node->_prev;
	node->_prev->_next = new;
	node->_prev = new;
}