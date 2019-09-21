#include"SList.h"
int main()
{
	SListHead _head;
	SListInit(&_head);
	SListPushBack(&_head, 1);
	SListPushBack(&_head, 3);
	SListPushBack(&_head, 3);
	SListPushBack(&_head, 4);
	SListPushBack(&_head, 3);
	SListPrint(&_head);
	SListEraseAfter(_head._head);
	SListPrint(&_head);
	system("pause");
	return 0;
}