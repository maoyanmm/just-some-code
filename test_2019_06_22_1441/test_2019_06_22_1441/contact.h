#ifndef  __CONTACT__H__
#define __CONTACT__H__
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum Option
{
	EXIT,
	ADD,
	SEAR,
	DEL,
	SHOW,
	CLEAR,
	SORT
};

#define MAX_NAME  20
#define MAX_TEL   11
#define MAX_ADDR  15
#define MAX_SEX   3
#define MAX_NUMPERSON      1000
//个人信息
typedef struct PersonInfo
{
	//name  age   tele  addr   sex
	char name[MAX_NAME];
	short age;
	char tele[MAX_TEL];
	char addr[MAX_TEL];
	char sex[MAX_SEX];
}PersonInfo;
//通讯录
typedef struct Contact
{
	PersonInfo per[MAX_NUMPERSON];
	int usedSize;//被使用的个数
}Contact;

void InitContact(Contact *pCon);
void AddContact(Contact* pCon);
int SearchContact(Contact* pCon);
void DelContact(Contact* pCon);
void ShowContact(Contact* pCon);
void ClearContact(Contact* pCon);

#endif// __CONTACT__H__
