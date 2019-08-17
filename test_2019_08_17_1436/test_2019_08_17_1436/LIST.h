#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node,*pList;

void Init_List(pList plist);
void Insert_head(pList plist,int val);
void Insert_tail(pList plist, int val);
void Show_list(pList plist);
Node *Last_k_node(pList plist,int k);
void Contrary_list(pList plist);
int Search(pList plist, int x);

