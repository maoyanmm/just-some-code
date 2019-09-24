#include"List.h"

int main()
{
	ListHead _head;
	ListInit(&_head);
	ListPushBack(&_head, 1);
	ListPushBack(&_head, 2);
	ListPushBack(&_head, 3);
	ListPushBack(&_head, 4);
	ListPushBack(&_head, 5);
	ListPrint(&_head);
	ListPushFront(&_head, 0);
	ListPrint(&_head);
	ListPopFront(&_head);
	ListPrint(&_head);
	ListInsert(_head._head->_next, -1);
	ListPrint(&_head);

	system("pause");
	return 0;
}