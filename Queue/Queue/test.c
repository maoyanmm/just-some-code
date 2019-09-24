#include"Queue.h"
int main()
{
	

	Queue q;
	/*int ret = 0;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5); ret = QueueEmpty(&q);
	printf("%d\n", ret);
	ret = QueueSize(&q);
	printf("%d\n", ret);
	QueuePrint(&q);
	ret = QueueEmpty(&q);
	printf("%d\n", ret);*/
	MyStack stack;
	myStackPush(&stack, 1);
	myStackPush(&stack, 2);
	myStackPush(&stack, 3);
	myStackPush(&stack, 4);
	int ret = myStackPop(&stack);
	printf("%d\n", ret);
	system("pause");
	return 0;
}