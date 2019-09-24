#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int DATATYPE;
typedef struct Stack
{
	DATATYPE* _arr;
	int top;
	int capicity;
}Stack;

void StackInit(Stack* ps);
void StackPush(Stack* ps,DATATYPE x);
void StackPop(Stack* ps);
DATATYPE StackTop(Stack *ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);
void StackPrint(Stack* ps);
int isValid(char * s);