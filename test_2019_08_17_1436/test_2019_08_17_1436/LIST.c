#include"LIST.h"
void Init_List(pList plist)
{
	assert(plist != NULL);
	plist->data = -1;
	plist->next = NULL;
}

static Node* Get_node(int val)
{
	Node *node = (Node*)malloc(sizeof(Node));
	assert(node != NULL);
	node->data = val;
	node->next = NULL;
	return node;
}

void Insert_head(pList plist, int val)
{
	assert(plist != NULL);
	Node *node = Get_node(val);
	node->next = plist->next;
	plist->next = node;
}

void Insert_tail(pList plist, int val)
{
	assert(plist != NULL);
	Node *node = Get_node(val);
	Node *p = plist;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = node;
}

void Show_list(pList plist)
{
	assert(plist != NULL);
	Node *p = plist->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

Node *Last_k_node(pList plist, int k)
{
	assert(plist != NULL);
	if (k < 0)
	{
		return NULL;
	}
	Node *p = plist;
	Node *q = plist;
	while (--k)
	{
		q = q->next;
		if (q->next == NULL)
		{
			return NULL;
		}
	}
	while (q->next != NULL)
	{
		p = p->next;
		q = q->next;
	}
	return q;
}

void Contrary_list(pList plist)
{
	assert(plist != NULL);
	Node *p = plist->next;
	Node *x = plist->next;
	Node *y = plist->next;
	Node *z = plist->next;
	if (x == NULL)
	{
		return 0;
	}
	x = x->next;
	if (x == NULL)
	{
		return 0;
	}
	y = y->next->next;
	if (y == NULL)
	{
		return 0;
	}
 do	{
		x->next = z;
		plist->next = x;
		if (y == NULL)
		{
			break;
		}
		z = x;
		x = y;
		y = y->next;
	}	while (x != NULL);
	p->next = NULL;
}

int Search(pList plist, int x)
{
	assert(plist != NULL);
	Node *p = plist->next;
	int count = 0;
	while (p != NULL)
	{
		count++;
		if (x == p->data)
		{
			return count;
		}
		p = p->next;
	}
	return -1;
}