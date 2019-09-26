#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capicity;
}Heap;

// parent = (child-1)/2
//child = parent*2 +1(2)
//堆是一个完全二叉树

void ShiftDown(HPDataType* a, int n, int root);
void HeapInit(Heap* hp);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
void Swap(HPDataType* a, HPDataType* b);
void HeapPrint(Heap* a);