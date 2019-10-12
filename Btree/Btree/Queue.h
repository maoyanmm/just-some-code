#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"BinaryTree.h"
typedef BTNode* DATATYPE;

typedef struct QueueNode
{
	DATATYPE _x;
	struct Queue* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _rear;
	int count;
}Queue;

typedef struct MyStack
{
	Queue Aq;
	Queue Bq;
}MyStack;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
QueueNode* BuyQueueNode(Queue* pq, DATATYPE x);
void QueuePush(Queue* pq, DATATYPE x);
void QueuePop(Queue* pq);
void QueuePrint(Queue* pq);
DATATYPE QueueFront(Queue* pq);
DATATYPE QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
MyStack* myStackCreate();
void myStackPush(MyStack* obj, int x);
int myStackPop(MyStack* obj);

