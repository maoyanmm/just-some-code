#include"SList.h"
void SListInit(SListHead *plist)
{
	assert(plist);
	plist->_head = NULL;
}

void SListDestory(SListHead *plist)
{
	assert(plist);
	SList* node = plist->_head;
	SList* next = node;
	while (node)
	{
		next = node->_next;
		free(node);
		node = next;
	}
	plist->_head = NULL;
}

void SListPrint(SListHead *plist)
{
	assert(plist);
	SList *node = plist->_head;
	while (node)
	{
		printf("%d->", node->_data);
		node = node->_next;
	}
	printf("\n");
}

SList* SListCreate(DATATYPE x)
{
	SList *node = (SList*)malloc(sizeof(SList));
	node->_data = x;
	node->_next = NULL;
	return node;
}

void SListPushBack(SListHead *plist, DATATYPE x)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		plist->_head = SListCreate(x);
	}
	else
	{
		SList *cur = plist->_head;
		while (cur->_next)
		{
			cur = cur->_next;
		}
		cur->_next = SListCreate(x);
	}
	
}

void SListEraseAfter(SList *pos)
{
	assert(pos);
	if (pos->_next == NULL)
	{
		return;
	}
	SList* node = pos->_next;
	SList* next = node->_next;
	pos->_next = next;
	free(node);
	node = NULL;
	
}


void SListPopBack(SListHead *plist)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		return;
	}
	else
	{
		SList* node = plist->_head;
		SList* prev = node;
		while (node->_next)
		{
			prev = node;
			node = node->_next;
		}
		if (node == plist->_head)
		{
			plist->_head = NULL;
		}
		else
		{
			free(node);
			node = NULL;
			prev->_next = NULL;
		}
		
	}
}

void SListPushFront(SListHead *plist, DATATYPE x)
{
	assert(plist);
	SList* new = SListCreate(x);
	SList* node = plist->_head;
	new->_next = node;
	plist->_head = new;
}

void SListPopFront(SListHead *plist)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		return;
	}
	SList* node = plist->_head;
	plist->_head = plist->_head->_next;
	free(node);
	node = NULL;
}

void SListRemoveAll(SListHead *plist, DATATYPE x)
{
	assert(plist);                                        //´ý¸Ä½ø
	SList* node = plist->_head;
	SList* prev = NULL;
	while (node)
	{
		if (node->_data == x)
		{
			if (prev == NULL)
			{
				plist->_head = node->_next;
			}
			else
			{
				prev->_next = node->_next;
			}
			free(node);
			node = prev->_next;
		}
		else
		{
			prev = node;
			node = node->_next;
		}
	}
}