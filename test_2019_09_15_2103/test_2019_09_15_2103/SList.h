#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
typedef int DATATYPE;

typedef struct SList
{
	DATATYPE _data;
	struct SListNode *_next;
}SList;

typedef struct SListHead
{
	SList *_head;
}SListHead;

void SListInit(SListHead *plist);
void SListDestory(SListHead *plist);
void SListPushFront(SListHead *plist,DATATYPE x); 
SList* SListCreate(DATATYPE x);
void SListPushBack(SListHead *plist, DATATYPE x);
void SListPrint(SListHead *plist);
void SListPopBack(SListHead *plist);
void SListPopFront(SListHead *plist);
void SListRemoveAll(SListHead *plist, DATATYPE x);
void SListEraseAfter(SList *pos);