#include"Oqueue.h"
int main()
{
	Oqueue q;
	OqueueInit(&q, 5);
	myCircularQueueEnQueue(&q, 1);
	myCircularQueueEnQueue(&q, 2);
	myCircularQueueEnQueue(&q, 3);
	myCircularQueueEnQueue(&q, 4);
	myCircularQueueEnQueue(&q, 5);
	myCircularQueueEnQueue(&q, 6);
	myCircularQueueEnQueue(&q, 7);
	myCircularQueueEnQueue(&q, 8);
	myCircularQueueEnQueue(&q, 9);
	myCircularQueueEnQueue(&q, 10);
	myCircularQueueEnQueue(&q, 11);
	myCircularQueueEnQueue(&q, 12);
	myCircularQueueEnQueue(&q, 13);
	myCircularQueueEnQueue(&q, 14);
	myCircularQueuePrint(&q);

	myCircularQueueDeQueue(&q);

	myCircularQueuePrint(&q);
	system("pause");
	return 0;
}