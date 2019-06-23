#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


enum Option
{
	EXIT,          //ö�١���һ����ֵĬ��Ϊ0�����水˳�����
	ADD,
	SEAR,
	DEL,
	SHOW,
	CLEAR,
	SORT
};

#define MAX_NAME 20           //�궨�����ֵ�����ֵ
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
	Personinfo per[MAX_PERSONNUM];  //�ṹ������
	int usedsize;     //����������ϵ��
}Contact;

void menu();
void InitContact(Contact *p);
void AddContact(Contact *p);
void DelContact(Contact *p);
int SearContact(Contact *p);
void ShowContact(Contact *p);
void ClearContact(Contact *p);
void SortContact(Contact *p);