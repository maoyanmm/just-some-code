#include"Seq.h"

int main()
{
	SeqList psl;
	SeqListInit(&psl,5);
	SeqListPushFront(&psl, 1);
	SeqListPushFront(&psl, 1);
	SeqListPushFront(&psl, 2);
	SeqListPushFront(&psl, 1);
	SeqListPushFront(&psl, 3);
	SeqListPushFront(&psl, 5);
	SeqListPushFront(&psl, 1);
	SeqListPushFront(&psl, 1);

	SeqListPrint(&psl);
	printf("\n");
	SeqListRemove(&psl, 1);
	SeqListPrint(&psl);
	printf("\n");
	SeqListModify(&psl, 4, 4);
	SeqListPrint(&psl);
	system("pause");
	return 0;
}