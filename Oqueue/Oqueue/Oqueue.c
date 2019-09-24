#include"Oqueue.h"
void OqueueInit(Oqueue* q,int k)
{
	assert(q);
	
	q->_capicity = k;
	q->_front = 0;
	q->_rear = 0;
	q->_arr = (DATATYPE*)malloc((q->_capicity+1)*sizeof(DATATYPE));
}

int myCircularQueueEnQueue(Oqueue* q, int value)
{
	assert(q);
	static int xrear = 0;
	if (q->_capicity == 0)
	{
		return 0;
	}
	if (q->_rear == q->_capicity)       //如果满了，就从头开始插，但是尾部还在arr[4]
	{
		q->_arr[xrear % q->_capicity] = value;
		xrear++;
	}
	else
	q->_arr[q->_rear++] = value;
	return 1;
}

void myCircularQueueDeQueue(Oqueue* q)
{
	assert(q);
	if (q->_rear == 0)
	{
		return;
	}
	q->_rear--;
}

int myCircularQueueFront(Oqueue* q)
{
	assert(q);
	if (q->_rear == 0)
	{
		return -1;
	}
	return q->_arr[q->_front];
}

int myCircularQueueRear(Oqueue* q)
{
	assert(q);
	if (q->_rear == 0)
	{
		return -1;
	}
	return q->_arr[q->_rear];
}

int myCircularQueueIsEmpty(Oqueue* q)
{
	assert(q);
	if (q->_rear == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int myCircularQueueIsFull(Oqueue* q)
{
	assert(q);
	if (q->_rear == q->_capicity)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void myCircularQueuePrint(Oqueue* q)
{
	assert(q);
	int i = 0;
	while (i != q->_rear)
	{
		printf("%d->",q->_arr[i]);
		i++;
	}
	printf("\n");
}