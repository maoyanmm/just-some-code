#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SLDataType int

typedef struct SeqList
{
	SLDataType *arry;   //动态数组
	size_t _size;       //数组里当前存储的数量
	size_t _capicity;   //数组的容量
}SeqList; 

void SeqListInit(SeqList *psl, size_t capicity);//初始化顺序表

void SeqListDestory(SeqList *psl);//清空顺序表

void CheckCapicity(SeqList *psl);//检查顺序表

void SeqListPushbBack(SeqList *psl, SLDataType x);//尾插

void SeqListPopBack(SeqList *psl);//尾删

void SeqListPushFront(SeqList *psl, SLDataType x);//头插

void SeqListPopFront(SeqList *psl);//头删

void SeqListPrint(SeqList *psl);//打印顺序表

int SeqListFind(SeqList *psl,SLDataType x);//查找顺序表中元素

void SeqListInsert(SeqList *psl, SLDataType x, size_t pos);//任意位置插入元素

void SeqListErase(SeqList *psl, size_t pos);//删除一个位置的元素

void SeqListRemove(SeqList *psl, SLDataType x);//删除所有x元素

void SeqListModify(SeqList *psl, size_t pos, SLDataType x);//修改某个位置的元素