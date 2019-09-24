#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int DATATYPE;
typedef struct Oqueue
{
	DATATYPE* _arr;
	int _front;
	int _rear;
	int _capicity;
}Oqueue;

void OqueueInit(Oqueue* q, int k); 
int myCircularQueueEnQueue(Oqueue* q, int value);
void myCircularQueueDeQueue(Oqueue* q);
int myCircularQueueFront(Oqueue* q);
int myCircularQueueRear(Oqueue* q);
int myCircularQueueIsEmpty(Oqueue* q);
int myCircularQueueIsFull(Oqueue* q);
void myCircularQueuePrint(Oqueue* q);