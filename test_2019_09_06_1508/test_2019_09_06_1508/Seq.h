#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define SLDataType int

typedef struct SeqList
{
	SLDataType *arry;   //��̬����
	size_t _size;       //�����ﵱǰ�洢������
	size_t _capicity;   //���������
}SeqList; 

void SeqListInit(SeqList *psl, size_t capicity);//��ʼ��˳���

void SeqListDestory(SeqList *psl);//���˳���

void CheckCapicity(SeqList *psl);//���˳���

void SeqListPushbBack(SeqList *psl, SLDataType x);//β��

void SeqListPopBack(SeqList *psl);//βɾ

void SeqListPushFront(SeqList *psl, SLDataType x);//ͷ��

void SeqListPopFront(SeqList *psl);//ͷɾ

void SeqListPrint(SeqList *psl);//��ӡ˳���

int SeqListFind(SeqList *psl,SLDataType x);//����˳�����Ԫ��

void SeqListInsert(SeqList *psl, SLDataType x, size_t pos);//����λ�ò���Ԫ��

void SeqListErase(SeqList *psl, size_t pos);//ɾ��һ��λ�õ�Ԫ��

void SeqListRemove(SeqList *psl, SLDataType x);//ɾ������xԪ��

void SeqListModify(SeqList *psl, size_t pos, SLDataType x);//�޸�ĳ��λ�õ�Ԫ��