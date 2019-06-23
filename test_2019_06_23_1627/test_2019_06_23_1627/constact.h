#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


enum Option
{
	EXIT,          //枚举。第一个的值默认为0，下面按顺序递增
	ADD,
	SEAR,
	DEL,
	SHOW,
	CLEAR,
	SORT
};

#define MAX_NAME 20           //宏定义各个值的最大值
#define MAX_ADDR 20      
#define MAX_TEL 11
#define MAX_SEX 3
#define MAX_PERSONNUM 1000

typedef struct Personinfo
{
	char name[MAX_NAME];
	char tele[MAX_TEL];
	short age;
	char addr[MAX_ADDR];
	char sex[MAX_SEX];
}Personinfo;

typedef struct Contact
{
	Personinfo per[MAX_PERSONNUM];  //结构体数组
	int usedsize;     //用来计数联系人
}Contact;

void menu();
void InitContact(Contact *p);
void AddContact(Contact *p);
void DelContact(Contact *p);
int SearContact(Contact *p);
void ShowContact(Contact *p);
void ClearContact(Contact *p);
void SortContact(Contact *p);