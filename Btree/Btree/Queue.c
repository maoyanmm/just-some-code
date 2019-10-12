#include"Queue.h"


void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = NULL;
	pq->_rear = NULL;
	pq->count = 0;
}

QueueNode* BuyQueueNode(Queue* pq, DATATYPE x)
{
	assert(pq);
	QueueNode* new = (QueueNode*)malloc(sizeof(QueueNode));
	new->_x = x;
	new->_next = NULL;
	return new;
}

void QueuePush(Queue* pq, DATATYPE x)
{
	assert(pq);
	if (pq->_front == NULL)
	{
		QueueNode* new = BuyQueueNode(pq, x);
		pq->_front = new;
		pq->_rear = new;
	}
	else
	{
		QueueNode* new = BuyQueueNode(pq, x);
		pq->_rear->_next = new;
		pq->_rear = pq->_rear->_next;
	}
	pq->count++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;
	pq->count--;
}

void QueuePrint(Queue* pq)
{
	assert(pq);
	while (pq->_front)
	{
		printf("%d,", pq->_front->_x);
		QueuePop(pq);
	}
	pq->count = 0;
	pq->_rear = NULL;
	printf("\n");
}

DATATYPE QueueFront(Queue* pq)
{
	assert(pq);
	return pq->_front->_x;
}

DATATYPE QueueBack(Queue* pq)
{
	assert(pq);
	return pq->_rear->_x;
}

void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur;
	while (pq->_front)
	{
		cur = pq->_front->_next;
		free(pq->_front);
		pq->_front = cur;
	}
	pq->count = 0;

}

int QueueEmpty(Queue* pq)
{
	assert(pq);
	if (pq->_front == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->count;
}


//***********************用队列实现栈**********************
MyStack* myStackCreate()
{
	MyStack* mystack = (MyStack*)malloc(sizeof(MyStack));
	return mystack;
}

void myStackPush(MyStack* obj, int x)
{
	assert(obj);
	if (QueueEmpty(&obj->Aq) == 0 && QueueEmpty(&obj->Bq) == 0)
	{
		QueuePush(&obj->Aq, x);
	}
	else if (QueueEmpty(&obj->Aq) == 0 && QueueEmpty(&obj->Bq) == 1)
	{
		QueuePush(&obj->Bq, x);
	}
	else if (QueueEmpty(&obj->Aq) == 1 && QueueEmpty(&obj->Bq) == 0)
	{
		QueuePush(&obj->Aq, x);
	}
	else
	{
		QueuePush(&obj->Aq, x);
	}
}

int myStackPop(MyStack* obj)
{
	assert(obj);
	Queue* x;
	Queue* y;
	int value;
	if (QueueEmpty(&obj->Aq) == 1)
	{
		x = &obj->Aq;
		y = &obj->Bq;
	}
	else
	{
		x = &obj->Bq;
		y = &obj->Aq;
	}
	while (x->count>1)
	{
		QueuePush(&y, x->_front->_x);
		QueuePop(&x);
	}
	value = x->_front->_x;
	QueuePop(&x);
	return value;
}